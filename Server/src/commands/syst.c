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
    send_client_message(client->control, "Remote system type is UNIX", 215);
}
