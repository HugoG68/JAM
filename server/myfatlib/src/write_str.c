/*
** EPITECH PROJECT, 2023
** Lib
** File description:
** write_str
*/

#include "../include/fatlib.h"

status write_str(int fd, char const *str)
{
    size_t len = 0;

    if (fd == -1 || my_strlen(str, &len) == ERROR)
        return ERROR;
    write(fd, str, len);
    return SUCCES;
}

status write_ln(int fd, char const *str)
{
    if (write_str(fd, str) == ERROR || write_char(fd, '\n') == ERROR)
        return ERROR;
    return SUCCES;
}
