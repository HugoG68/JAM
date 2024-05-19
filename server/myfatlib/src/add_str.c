/*
** EPITECH PROJECT, 2023
** Lib
** File description:
** add_str
*/

#include "../include/fatlib.h"

status add_str(char const *str1, char const *str2, char **pointer_str)
{
    size_t len1 = 0;
    size_t len2 = 0;
    char *res = NULL;

    if (str1 == NULL || str2 == NULL || pointer_str == NULL)
        return ERROR;
    my_strlen(str1, &len1);
    my_strlen(str2, &len2);
    res = malloc(len1 + len2 + 1);
    for (size_t i = 0; i < len1; i++)
        res[i] = str1[i];
    for (size_t i = 0; i < len2; i++)
        res[i + len1] = str2[i];
    res[len1 + len2] = '\0';
    if (*pointer_str != NULL)
        free(*pointer_str);
    *pointer_str = res;
    return SUCCES;
}

status add_strs(char const **list, char **ptr_str)
{
    char *res = NULL;
    size_t list_len = 0;

    if (arr_len((void const **)list, &list_len) == ERROR || ptr_str == NULL)
        return ERROR;
    if (list_len == 0)
        return ERROR;
    my_strdup(list[0], &res);
    for (size_t i = 1; i < list_len; i++)
            add_str(res, list[i], &res);
    if (*ptr_str != NULL)
        free(*ptr_str);
    *ptr_str = res;
    return SUCCES;
}
