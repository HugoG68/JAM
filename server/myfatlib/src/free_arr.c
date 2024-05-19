/*
** EPITECH PROJECT, 2023
** Lib
** File description:
** free_arr
*/

#include "../include/fatlib.h"

void free_arr(void **arr)
{
    if (arr == NULL)
        return;
    for (size_t i = 0; arr[i] != NULL; i++)
        free(arr[i]);
    free(arr);
}
