/*
** EPITECH PROJECT, 2024
** myftp
** File description:
** open_server
*/

#include "myftp.h"

void exit_error(ftp_t *my_ftp, char const *error_msg)
{
    write_ln(STDERR_FILENO, error_msg);
    destroy_ftp(my_ftp);
    exit(ERROR);
}

ftp_t *open_server(int port, char const *path)
{
    ftp_t *my_ftp = construct_ftp(path);
    int b_r = -1;
    int listen_resp = -1;

    my_ftp->main_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (my_ftp->main_socket == -1)
        exit_error(my_ftp, "MAIN_SOCKET");
    my_ftp->in->sin_family = AF_INET;
    my_ftp->in->sin_port = htons(port);
    my_ftp->in->sin_addr.s_addr = inet_addr("127.0.0.1");
    b_r = bind(my_ftp->main_socket, (struct sockaddr *)my_ftp->in,
    sizeof(struct sockaddr_in));
    if (b_r == -1)
        exit_error(my_ftp, "BIND");
    listen_resp = listen(my_ftp->main_socket, 50);
    if (listen_resp == -1)
        exit_error(my_ftp, "LISTEN RESP");
    my_ftp->user_count = my_ftp->main_socket + 1;
    my_ftp->client = NULL;
    my_ftp->rank = NULL;
    return my_ftp;
}
