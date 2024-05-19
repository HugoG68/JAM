/*
** EPITECH PROJECT, 2023
** Lib
** File description:
** my_strdup
*/

#include "../include/fatlib.h"

status my_strdup(char const *str, char **pointer_str)
{
    size_t len = 0;
    char *res = NULL;

    if (my_strlen(str, &len) || pointer_str == NULL)
        return ERROR;
    res = malloc(len + 1);
    for (size_t i = 0; i <= len; i++)
        res[i] = str[i];
    if (*pointer_str != NULL)
        free(*pointer_str);
    *pointer_str = res;
    return SUCCES;
}
