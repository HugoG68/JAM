/*
** EPITECH PROJECT, 2024
** myftp
** File description:
** quit
*/

#include "../myftp.h"

void quit(struct command_s *this, client_t *client, char **command)
{
    size_t len = 0;

    if (is_not_logged(client))
        return;
    arr_len((const void **)command, &len);
    if (this->arg_nb != len) {
        write_user(client->socket, SYNTAX_ERROR);
        return;
    }
    write_user(client->socket, LOG_OUT);
    close(client->socket);
    client->socket = -1;
}
