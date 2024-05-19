/*
** EPITECH PROJECT, 2024
** myftp
** File description:
** main_node
*/

#include "myftp.h"

void fd_setting(ftp_t *my_ftp)
{
    FD_ZERO(&my_ftp->reads);
    FD_SET(my_ftp->main_socket, &my_ftp->reads);
    if (!my_ftp->client)
        return;
    clear_user(&(my_ftp->client));
    for (client_t *head = my_ftp->client; head; head = head->next) {
        FD_SET(head->socket, &my_ftp->reads);
    }
}

void main_node(ftp_t *my_ftp)
{
    int len_fd = -1;
    int quit = 0;

    while (quit == 0) {
        fd_setting(my_ftp);
        len_fd = select(my_ftp->user_count, &my_ftp->reads, NULL,
        NULL, NULL);
        if (FD_ISSET(my_ftp->main_socket, &my_ftp->reads) &&
        len_fd > 0) {
            write_ln(STDERR_FILENO, "connect_new_user");
            handle_fds(len_fd, my_ftp);
        }
        read_fds(my_ftp);
    }
}
