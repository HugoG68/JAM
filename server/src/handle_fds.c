/*
** EPITECH PROJECT, 2024
** myftp
** File description:
** handle_fds
*/

#include "myftp.h"

int handle_fd(ftp_t *my_ftp)
{
    int res = accept(my_ftp->main_socket,
    &my_ftp->client_address, &my_ftp->len);

    if (res == -1) {
        write_ln(STDERR_FILENO, "accept fail");
        return 0;
    }
    if (res > my_ftp->user_count - 1)
        my_ftp->user_count = res + 1;
    append_client(my_ftp->path, res, &(my_ftp->client));
    write_user(res, SERVICE_READY);
    return 0;
}

int handle_fds(int len_fds, ftp_t *my_ftp)
{
    for (int i = 0; i < len_fds; i++)
        handle_fd(my_ftp);
    return 0;
}

void read_fds(ftp_t *my_ftp)
{
    for (client_t *head = my_ftp->client; head; head = head->next)
        if (FD_ISSET(head->socket, &my_ftp->reads))
            read_user(head, &my_ftp->rank);
}
