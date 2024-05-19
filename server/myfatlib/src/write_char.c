/*
** EPITECH PROJECT, 2023
** myunilib
** File description:
** write_char
*/

#include "../include/fatlib.h"

status write_char(int fd, char c)
{
    if (fd == -1)
        return ERROR;
    write(fd, &c, 1);
    return SUCCES;
}
