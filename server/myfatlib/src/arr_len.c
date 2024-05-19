/*
** EPITECH PROJECT, 2023
** Lib
** File description:
** count_arg
*/

#include "../include/fatlib.h"

status arr_len(void const **arr, size_t *pointer_count)
{
    if (pointer_count == NULL || arr == NULL)
        return ERROR;
    for (; arr[*pointer_count]; (*pointer_count)++);
    return SUCCES;
}
