/*
** EPITECH PROJECT, 2018
** help.c
** File description:
** HELP command
*/

#include "server.h"

void help_action(server_utils_t *utils, char *param,
        client_sks_t *client)
{
    if (!client->is_connect) {
        send_client_code(client->control, 530);
        return;
    }
    send_client_code(client->control, 214);
}
