/*
** EPITECH PROJECT, 2018
** SYST.c
** File description:
** SYST command
*/

#include "server.h"

void syst_action(server_utils_t __attribute__((unused)) *utils,
        char __attribute__((unused)) *param,
        client_sks_t *client)
{
    if (!client->is_connect) {
        send_client_code(client->control, 530);
        return;
    }
    send_client_code(client->control, 215);
}
