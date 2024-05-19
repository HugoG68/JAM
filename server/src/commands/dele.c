/*
** EPITECH PROJECT, 2024
** myftp
** File description:
** dele
*/

#include "../myftp.h"

static char *get_file_path(client_t *client, char *arg)
{
    char *filepath = NULL;
    char *buffer = NULL;
    char const *strs[] = {client->pwd, "/", arg, NULL};

    if (arg[0] == '/')
        filepath = realpath(arg, NULL);
    if (arg[0] != '/') {
        if (add_strs(strs, &buffer) == ERROR) {
            write_user(client->socket, SYNTAX_ERROR);
            return NULL;
        }
        filepath = realpath(buffer, NULL);
    }
    if (filepath == NULL) {
        write_user(client->socket, SYNTAX_ERROR);
        return NULL;
    }
    return filepath;
}

void dele(struct command_s *this, client_t *client, char **command)
{
    size_t len = 0;
    char *filepath = NULL;

    if (is_not_logged(client))
        return;
    arr_len((const void **)command, &len);
    if (this->arg_nb != len) {
        write_user(client->socket, SYNTAX_ERROR);
        return;
    }
    filepath = get_file_path(client, command[1]);
    if (filepath == NULL) {
        write_user(client->socket, SYNTAX_ERROR);
        return;
    }
    remove(filepath);
    free(filepath);
    write_user(client->socket, FILE_REQUSET_OK);
}
