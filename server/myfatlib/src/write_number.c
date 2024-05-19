/*
** EPITECH PROJECT, 2023
** myunilib
** File description:
** write_number
*/


#include "../include/fatlib.h"

status write_number(int fd, int nbr)
{
    char c;

    if (fd == -1)
        return ERROR;
    if (nbr < 0) {
        write_char(fd, '-');
        return write_number(fd, -nbr);
    }
    if (nbr < 10) {
        c = DIGIT_TO_CHAR(nbr);
        write_char(fd, c);
    } else {
        c = DIGIT_TO_CHAR(nbr % 10);
        write_number(fd, nbr / 10);
        write_char(fd, c);
    }
    return SUCCES;
}

status write_ln_nbr(int fd, int nbr)
{
    if (fd == -1)
        return ERROR;
    write_number(fd, nbr);
    write_char(fd, '\n');
    return SUCCES;
}
