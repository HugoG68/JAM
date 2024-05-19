/*
** EPITECH PROJECT, 2024
** myftp
** File description:
** cwd
*/

#include "../myftp.h"

char *is_dir(client_t *client, char *new_pwd)
{
    struct stat s;

    if (stat(new_pwd, &s)) {
        write_user(client->socket, SYNTAX_ERROR);
        free(new_pwd);
        return NULL;
    }
    if (!S_ISDIR(s.st_mode)) {
        write_user(client->socket, SYNTAX_ERROR);
        free(new_pwd);
        return NULL;
    }
    return new_pwd;
}

char *get_file_path(client_t *client, char *arg)
{
    char *new_pwd = NULL;
    char *buffer = NULL;
    char const *strs[] = {client->pwd, "/", arg, NULL};

    if (arg[0] == '/')
        new_pwd = realpath(arg, NULL);
    if (arg[0] != '/') {
        if (add_strs(strs, &buffer) == ERROR) {
            write_user(client->socket, SYNTAX_ERROR);
            return NULL;
        }
        new_pwd = realpath(buffer, NULL);
    }
    if (new_pwd == NULL) {
        write_user(client->socket, SYNTAX_ERROR);
        return NULL;
    }
    return is_dir(client, new_pwd);
}

void cwd(struct command_s *this, client_t *client, char **command)
{
    size_t len = 0;
    char *new_pwd = NULL;

    if (is_not_logged(client))
        return;
    arr_len((const void **)command, &len);
    if (this->arg_nb != len) {
        write_user(client->socket, SYNTAX_ERROR);
        return;
    }
    new_pwd = get_file_path(client, command[1]);
    if (!new_pwd)
        return;
    free(client->pwd);
    client->pwd = new_pwd;
    write_user(client->socket, FILE_REQUSET_OK);
}
