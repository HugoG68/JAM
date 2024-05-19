/*
** EPITECH PROJECT, 2023
** Lib
** File description:
** my_strlen
*/

#include "../include/fatlib.h"

status my_strlen(char const *str, size_t *len_pointer)
{
    if (str == NULL || len_pointer == NULL)
        return ERROR;
    *len_pointer = 0;
    while (str[*len_pointer]) {
        (*len_pointer)++;
    }
    return SUCCES;
}
