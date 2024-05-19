/*
** EPITECH PROJECT, 2024
** myftp
** File description:
** read_user
*/

#include "myftp.h"
#include <fcntl.h>
#include <sys/stat.h>

void insert(rank_t **list, rank_t *new_rank)
{
    rank_t *tmp = *list;

    if (!tmp) {
        *list = new_rank;
        return;
    }

    if (tmp->score < new_rank->score) {
        new_rank->next = tmp;
        *list = new_rank;
        return;
    }


    for (; tmp; tmp = tmp->next) {
        if (tmp->next == NULL) {
            tmp->next = new_rank;
            break;
        }
        if (tmp->next->score < new_rank->score) {
            new_rank->next = tmp->next;
            tmp->next = new_rank;
            break;
        }
    }
    tmp = *list;

    for (size_t i = 0; tmp; tmp = tmp->next) {
        tmp->index = i;
        i++;
    }
}

void send_rank(client_t *client, rank_t *list)
{
    char *buffer = malloc(10000);
    rank_t *tmp = list;
    size_t i = 0;
    int fd = open("/tmp/rank", O_CREAT | O_WRONLY | O_TRUNC, 0666);
    struct stat st;

    for (; tmp; tmp = tmp->next) {
        sprintf(buffer, "%s %ld", tmp->name, tmp->score);
        write(fd, buffer, strlen(buffer));
        i++;
        if (i == 10)
            break;
    }
    close(fd);
    fd = open("/tmp/rank", O_RDONLY);
    free(buffer);
    stat("/tmp/rank", &st);
    buffer = malloc(st.st_size + 1);
    buffer[st.st_size] = '\0';
    read(fd, buffer, st.st_size);
    write(1, buffer, st.st_size);
    write(1, "\n\n========\n\n", 12);
    write_user(client->socket, buffer);
    close(fd);
}

void find_comand(client_t *client, char **commands, rank_t **list)
{
    size_t max = 0;
    rank_t *new_rank = NULL;

    arr_len((void const **)commands, &max);
    if (!max)
        return;
    new_rank = malloc(sizeof(rank_t));
    new_rank->name = NULL;
    my_strdup(commands[0], &new_rank->name);
    new_rank->score = atoi(commands[1]);
    new_rank->index = 0;
    new_rank->next = NULL;
    insert(list, new_rank);
    send_rank(client, *list);
}

void read_user(client_t *client, rank_t **list)
{
    char *buffer = malloc(32000);
    char **command = NULL;
    int readed = 0;
    char *pos_end = NULL;

    readed = read(client->socket, buffer, 32000);
    if (readed <= 0) {
        free(buffer);
        return;
    }
    buffer[readed] = '\0';
    pos_end = strstr(buffer, CRLF);
    if (pos_end) {
        pos_end[0] = '\0';
        my_str_separated(buffer, " \t\n", &command);
        find_comand(client, command, list);
        free_arr((void **)command);
    }
    free(buffer);
}

void clear_user(client_t **client)
{
    for (client_t *node = *client; node; node = node->next) {
        if (node->socket != -1)
            continue;
        destroy_client(node, client);
        clear_user(client);
        break;
    }
}
