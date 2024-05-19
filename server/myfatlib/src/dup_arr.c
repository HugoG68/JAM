/*
** EPITECH PROJECT, 2023
** lib
** File description:
** dup_arr
*/

#include "../include/fatlib.h"

status dup_arr(char **arr, char ***pointer_list)
{
    size_t len = 0;
    char **res = NULL;

    if (arr_len((void const **)arr, &len) == ERROR || pointer_list == NULL)
        return ERROR;
    res = malloc(sizeof(char *) * (len + 1));
    for (size_t i = 0; i < len; i++)
        my_strdup(arr[i], res + i);
    res[len] = NULL;
    free_arr((void **)*pointer_list);
    *pointer_list = res;
    return SUCCES;
}
