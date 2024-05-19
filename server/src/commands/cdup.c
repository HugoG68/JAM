/*
** EPITECH PROJECT, 2024
** myftp
** File description:
** cdup
*/

#include "../myftp.h"

void cdup(struct command_s *this, client_t *client, char **command)
{
    size_t len = 0;
    char *new_pwd = NULL;
    char *buffer = NULL;

    if (is_not_logged(client))
        return;
    arr_len((const void **)command, &len);
    if (this->arg_nb != len) {
        write_user(client->socket, SYNTAX_ERROR);
        return;
    }
    add_str(client->pwd, "/..", &buffer);
    new_pwd = realpath(buffer, NULL);
    free(buffer);
    if (new_pwd) {
        free(client->pwd);
        client->pwd = new_pwd;
        write_user(client->socket, FILE_REQUSET_OK);
    }
    write_user(client->socket, SYNTAX_ERROR);
}
