/*
** EPITECH PROJECT, 2024
** myftp
** File description:
** main
*/

#include "myftp.h"

int main(int argc, char const *argv[])
{
    int port = 0;
    char *path = NULL;
    ftp_t *my_ftp;

    if (argc < 2 || argc > 3)
        return ERROR;
    if (argc == 2)
        check_print_help(argv[1]);
    if (my_get_nbr(argv[1], &port, false) == ERROR)
        return ERROR;
    path = realpath(argv[2], NULL);
    if (!path)
        return ERROR;
    my_ftp = open_server(port, path);
    main_node(my_ftp);
    destroy_ftp(my_ftp);
    return SUCCES;
}
