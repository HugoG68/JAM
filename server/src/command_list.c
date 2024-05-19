/*
** EPITECH PROJECT, 2024
** myftp
** File description:
** command_list
*/

#include "myftp.h"

void make_command_list_name(command_t *list)
{
    list[IDX_USER].name = "USER";
    list[IDX_PASS].name = "PASS";
    list[IDX_CWD].name = "CWD";
    list[IDX_CDUP].name = "CDUP";
    list[IDX_QUIT].name = "QUIT";
    list[IDX_DELE].name = "DELE";
    list[IDX_PWD].name = "PWD";
    list[IDX_PASV].name = "PASV";
    list[IDX_PORT].name = "PORT";
    list[IDX_HELP].name = "HELP";
    list[IDX_NOOP].name = "NOOP";
    list[IDX_RETR].name = "RETR";
    list[IDX_STOR].name = "STOR";
    list[IDX_LIST].name = "LIST";
}

void make_command_list_arg_nb(command_t *list)
{
    list[IDX_USER].arg_nb = 2;
    list[IDX_PASS].arg_nb = 1;
    list[IDX_CWD].arg_nb = 2;
    list[IDX_CDUP].arg_nb = 1;
    list[IDX_QUIT].arg_nb = 1;
    list[IDX_DELE].arg_nb = 2;
    list[IDX_PWD].arg_nb = 1;
    list[IDX_PASV].arg_nb = 1;
    list[IDX_PORT].arg_nb = 2;
    list[IDX_HELP].arg_nb = 1;
    list[IDX_NOOP].arg_nb = 1;
    list[IDX_RETR].arg_nb = 2;
    list[IDX_STOR].arg_nb = 2;
    list[IDX_LIST].arg_nb = 1;
}

void make_command_list_func(command_t *list)
{
    list[IDX_USER].func = &user;
    list[IDX_PASS].func = &pass;
    list[IDX_CWD].func = &cwd;
    list[IDX_CDUP].func = &cdup;
    list[IDX_QUIT].func = &quit;
    list[IDX_DELE].func = &dele;
    list[IDX_PWD].func = &pwd;
    list[IDX_PASV].func = NULL;
    list[IDX_PORT].func = NULL;
    list[IDX_HELP].func = &help;
    list[IDX_NOOP].func = &noop;
    list[IDX_RETR].func = NULL;
    list[IDX_STOR].func = NULL;
    list[IDX_LIST].func = NULL;
}

command_t *make_command_list(void)
{
    command_t *list = malloc(sizeof(command_t) * IDX_MAX);

    make_command_list_name(list);
    make_command_list_func(list);
    make_command_list_arg_nb(list);
    return list;
}
