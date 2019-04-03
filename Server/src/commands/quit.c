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
    send_client_message(client->control,
            "Service closing control connection.", 221);
    close(client->data);
    close(client->control);
    *client = (client_sks_t){0, 0};
}
