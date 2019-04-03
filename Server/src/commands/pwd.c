/*
** EPITECH PROJECT, 2018
** pwd.c
** File description:
** get current directorie
*/

#include "server.h"

void pwd_action(server_utils_t *utils,
        __attribute__((unused)) char *params,
        __attribute__((unused)) client_sks_t *client_info)
{
    send_client_message(client_info->control, utils->pwd, 200);
}
