/*
** EPITECH PROJECT, 2024
** myftp
** File description:
** is_not_logged
*/

#include "myftp.h"

bool is_not_logged(client_t *client)
{
    if (client->is_connected == LOGGED)
        return false;
    write_user(client->socket, NOT_LOGGED);
    return true;
}
