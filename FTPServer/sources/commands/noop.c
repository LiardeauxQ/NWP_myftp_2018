/*
** EPITECH PROJECT, 2018
** noop.c
** File description:
** NOOP command
*/

#include "server.h"

void noop_action(server_utils_t __attribute__((unused)) *utils,
        char __attribute__((unused)) *param,
        client_sks_t *client)
{
    if (client->is_connect != 2) {
        send_client_code(client->control, 530);
        return;
    }
    send_client_code(client->control, 200);
}
