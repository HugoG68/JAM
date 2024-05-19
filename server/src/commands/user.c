/*
** EPITECH PROJECT, 2024
** myftp
** File description:
** user
*/


#include "../myftp.h"

void user(struct command_s *this, client_t *client, char **command)
{
    size_t len = 0;

    arr_len((const void **)command, &len);
    if (this->arg_nb != len) {
        write_user(client->socket, SYNTAX_ERROR);
        return;
    }
    if (same_str(command[1], USERNAME_DEFAULT)) {
        client->is_connected = WAIT_PASS;
        write_user(client->socket, USER_OK_WHERE_PASS);
    } else
        write_user(client->socket, ERR_USR_PASS);
}
