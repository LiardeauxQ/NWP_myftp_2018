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
    send_client_message(client->control, 200);
}
