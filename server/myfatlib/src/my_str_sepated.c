/*
** EPITECH PROJECT, 2023
** my_unilib
** File description:
** my_str_sepated
*/

#include "../include/fatlib.h"

int count_occurence(char *buff, char const *exclude)
{
    int count = 0;

    for (size_t i = 0; buff[i]; i++) {
        if (!contain(buff[i], exclude) &&
        (contain(buff[i + 1], exclude) || !buff[i + 1]))
            count++;
    }
    return count;
}

char **separate(size_t arg_count, char *to_parse, char const *exclude)
{
    size_t len = 0;
    char **result = NULL;

    result = malloc(sizeof(char *) * (1 + arg_count));
    result[arg_count] = NULL;
    for (size_t i = 0; i < arg_count; i++) {
        len = 0;
        while (contain(*to_parse, exclude))
            to_parse++;
        for (; to_parse[len] && !contain(to_parse[len], exclude); len++);
        result[i] = malloc(len + 1);
        result[i][len] = 0;
        for (size_t c = 0; c < len; c++) {
            result[i][c] = *to_parse;
            to_parse++;
        }
    }
    return result;
}

status my_str_separated(char *buff, char const *exclude, char ***list_pointer)
{
    char **result = NULL;
    size_t arg_count = 0;

    if (buff == NULL || exclude == NULL || list_pointer == NULL)
        return ERROR;
    arg_count = count_occurence(buff, exclude);
    result = separate(arg_count, buff, exclude);
    free_arr((void **)*list_pointer);
    *list_pointer = result;
    return SUCCES;
}
