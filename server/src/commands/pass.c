/*
** EPITECH PROJECT, 2024
** myftp
** File description:
** pass
*/

#include "../myftp.h"

void pass(struct command_s *this, client_t *client, char **command)
{
    size_t len = 0;

    arr_len((const void **)command, &len);
    if (client->is_connected != WAIT_PASS) {
        write_user(client->socket, ERR_SEQUENCE);
        return;
    }
    if (this->arg_nb != len) {
        write_user(client->socket, ERR_USR_PASS);
        return;
    }
    client->is_connected = LOGGED;
    write_user(client->socket, LOGGED_IN);
}
