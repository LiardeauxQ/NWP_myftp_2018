/*
** EPITECH PROJECT, 2018
** cdup.c
** File description:
** CDUP command
*/

#include "server.h"

void cdup_action(server_utils_t *utils, char __attribute__((unused)) *param,
        client_sks_t *client)
{
    if (chdir(utils->home)) {
        send_client_message(client->control, 666);
        return;
    }
    free(utils->pwd);
    utils->pwd = utils->home;
    send_client_message(client->control, 200);
}
