/*
** EPITECH PROJECT, 2023
** Lib
** File description:
** my_get_nbr
*/

#include "../include/fatlib.h"

bool valid_size_int(char const *str, bool is_neg)
{
    char const *n_max = "2147483647";
    char const *n_min = "-2147483648";
    size_t const n_max_len = 10;
    size_t const n_min_len = 11;
    size_t len = 0;
    char const *n = (is_neg) ? n_min : n_max;

    my_strlen(str, &len);
    if ((len > n_min_len && is_neg) || (len > n_max_len && !is_neg))
        return false;
    if ((len != n_min_len || !is_neg) && (len != n_max_len || is_neg))
        return true;
    for (size_t i = is_neg; i < len; i++) {
        if (str[i] < n[i])
            break;
        if (str[i] > n[i])
            return false;
    }
    return true;
}

bool valid_nbr_str(char const *str, bool can_be_neg)
{
    int i = 1;
    bool is_neg = false;

    if (str == NULL)
        return false;
    is_neg = str[0] == '-';
    if (!IS_NB(str[0]) && (!can_be_neg || !is_neg))
        return false;
    for (; str[i] && IS_NB(str[i]); i++);
    if (str[i] || (is_neg && i <= 1))
        return false;
    return valid_size_int(str, is_neg);
}

status my_get_nbr(char const *str, int *nbr_address, bool can_be_neg)
{
    int i = 0;
    bool is_neg = false;

    *nbr_address = 0;
    if (!valid_nbr_str(str, can_be_neg))
        return ERROR;
    is_neg = str[0] == '-';
    i = is_neg;
    for (; str[i]; i++) {
        *nbr_address *= 10;
        *nbr_address += CHAR_TO_DIGIT(str[i]);
    }
    if (is_neg)
        *nbr_address = 0 - *nbr_address;
    return SUCCES;
}
