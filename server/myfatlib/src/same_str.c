/*
** EPITECH PROJECT, 2023
** Lib
** File description:
** same_str
*/

#include "../include/fatlib.h"

bool same_str(char const *str_a, char const *str_b)
{
    size_t len_a = 0;
    size_t len_b = 0;
    size_t i = 0;

    if (str_a == str_b)
        return true;
    if (my_strlen(str_a, &len_a) == ERROR || my_strlen(str_b, &len_b) == ERROR)
        return false;
    if (len_a != len_b)
        return false;
    for (; i < len_a && str_a[i] == str_b[i]; i++);
    return (len_a == i);
}

bool same_end(char const *str, char const *end)
{
    size_t len_end = 0;
    size_t len_str = 0;

    if (my_strlen(end, &len_end) == ERROR || my_strlen(str, &len_str) == ERROR)
    if (len_end > len_str)
        return false;
    return same_str(str + (len_str - len_end), end);
}
