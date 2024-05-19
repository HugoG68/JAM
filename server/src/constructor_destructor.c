/*
** EPITECH PROJECT, 2024
** myftp
** File description:
** constructor_destructor
*/

#include "myftp.h"

ftp_t *construct_ftp(char const *path)
{
    ftp_t *my_ftp = malloc(sizeof(ftp_t));

    my_ftp->main_socket = -1;
    my_ftp->in = malloc(sizeof(struct sockaddr_in));
    my_ftp->len = sizeof(struct sockaddr);
    my_ftp->path = path;
    my_ftp->commands = make_command_list();
    return my_ftp;
}

void destroy_ftp(ftp_t *my_ftp)
{
    if (my_ftp->main_socket != -1)
        close(my_ftp->main_socket);
    free(my_ftp->in);
    free(my_ftp->commands);
    free(my_ftp);
}
