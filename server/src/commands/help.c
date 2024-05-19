/*
** EPITECH PROJECT, 2024
** myftp
** File description:
** help
*/

#include "../myftp.h"

void help(struct command_s *this, client_t *client, char **command)
{
    size_t len = 0;

    if (is_not_logged(client))
        return;
    arr_len((const void **)command, &len);
    if (this->arg_nb != len) {
        write_user(client->socket, SYNTAX_ERROR);
        return;
    }
    write_user(client->socket, HELP_RESP);
}
