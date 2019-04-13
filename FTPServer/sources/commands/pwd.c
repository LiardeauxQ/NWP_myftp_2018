/*
** EPITECH PROJECT, 2018
** pwd.c
** File description:
** get current directorie
*/

#include "server.h"

void pwd_action(server_utils_t *utils,
        __attribute__((unused)) char *params,
        __attribute__((unused)) client_sks_t *client)
{
    if (client->is_connect != 2) {
        send_client_code(client->control, 530);
        return;
    }
    send_client_message(client->control, utils->pwd, 257);
}
