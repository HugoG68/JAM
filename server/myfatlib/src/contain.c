/*
** EPITECH PROJECT, 2023
** corewar
** File description:
** contain
*/

#include "../include/fatlib.h"

bool contain(char c, char const *what)
{
    if (what == NULL)
        return false;
    for (size_t i = 0; what[i]; i++)
        if (c == what[i])
            return true;
    return false;
}

bool str_contain(char const *str, char const *what, bool only)
{
    size_t i = 0;

    if (str == NULL || what == NULL)
        return false;
    for (; str[i] && (!only || contain(str[i], what)); i++)
        if (contain(str[i], what) && !only)
            return true;
    return (i && !str[i] && only);
}
