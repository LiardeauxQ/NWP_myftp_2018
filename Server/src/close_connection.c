/*
** EPITECH PROJECT, 2018
** close_connection.c
** File description:
** close server connection
*/

#include "server.h"

void close_server_connection(server_utils_t *utils)
{
    free(utils->home);
    free(utils->pwd);
    close(utils->control.socket);
}
