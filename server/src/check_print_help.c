/*
** EPITECH PROJECT, 2024
** myftp
** File description:
** check_print_help
*/

#include "myftp.h"

void check_print_help(char const *arg)
{
    if (!same_str(arg, "-help"))
        exit(ERROR);
    write_ln(STDOUT_FILENO, "USAGE: ./myftp port path");
    write_str(STDOUT_FILENO, "      port  is the port number on which the");
    write_ln(STDOUT_FILENO, " server socket listens");
    write_str(STDOUT_FILENO, "      path  is the path to the home directory");
    write_ln(STDOUT_FILENO, " for the Anonymous user");
    exit(SUCCES);
}
