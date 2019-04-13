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
    if (client->is_connect != 2) {
        send_client_code(client->control, 530);
        return;
    }
    send_client_code(client->control, 250);
}
