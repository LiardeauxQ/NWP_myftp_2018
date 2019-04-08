/*
** EPITECH PROJECT, 2018
** dele.c
** File description:
** DELE command
*/

#include "server.h"

void dele_action(server_utils_t *utils, char *param,
        client_sks_t *client)
{
    if (!client->is_connect) {
        send_client_code(client->control, 530);
        return;
    }
}
