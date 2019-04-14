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
    if (client->is_connect != 2) {
        send_client_code(client->control, 530);
        return;
    }
    if (chdir(utils->home)) {
        send_client_code(client->control, 550);
        return;
    }
    free(utils->pwd);
    utils->pwd = utils->home;
    send_client_code(client->control, 200);
}
