/*
** EPITECH PROJECT, 2023
** myunilib
** File description:
** push
*/

#include "../include/fatlib.h"

status push(void ***list_pointer, void *new_elem)
{
    size_t list_len = 0;
    void **res = NULL;

    if (list_pointer == NULL || new_elem == NULL)
        return ERROR;
    arr_len((void const **)*list_pointer, &list_len);
    res = malloc(list_len + 2);
    for (size_t i = 0; i < list_len; i++)
        res[i] = (*list_pointer)[i];
    res[list_len] = new_elem;
    res[list_len + 1] = NULL;
    if (*list_pointer != NULL)
        free(*list_pointer);
    *list_pointer = res;
    return SUCCES;
}
