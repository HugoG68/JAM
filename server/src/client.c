/*
** EPITECH PROJECT, 2024
** myftp
** File description:
** client
*/

#include "myftp.h"

void append_client(char const *path, int socket, client_t **client_list_p)
{
    client_t *head = NULL;
    client_t *client = malloc(sizeof(client_t));

    client->is_connected = DISCONNECTED;
    client->socket = socket;
    client->pwd = NULL;
    my_strdup(path, &client->pwd);
    client->next = NULL;
    client->prev = NULL;
    if (*client_list_p) {
        head = *client_list_p;
        head->prev = client;
        client->next = head;
    }
    *client_list_p = client;
}

void destroy_client(client_t *client, client_t **head_p)
{
    if (client->next)
        client->next->prev = client->prev;
    if (client->prev)
        client->prev->next = client->next;
    else
        *head_p = client->next;
    free(client->pwd);
    free(client);
}

void destroy_clients(client_t *client)
{
    client_t *node;

    while (client) {
        node = client;
        client = client->next;
        if (client->socket != -1)
            close(client->socket);
        free(node->pwd);
        free(node);
    }
}
