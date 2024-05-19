/*
** EPITECH PROJECT, 2024
** myftp
** File description:
** write_user
*/

#include "myftp.h"

void write_user(int fd, char const *str)
{
    char *buffer = NULL;

    add_str(str, CRLF, &buffer);
    write_str(fd, buffer);
}
