/*
** EPITECH PROJECT, 2018
** quit.c
** File description:
** QUIT command
*/

#include "server.h"

void quit_action(server_utils_t *utils, char *param,
        client_sks_t *client)
{
    send_client_code(client->control, 221);
    close(client->control);
    free_client(client);
}
