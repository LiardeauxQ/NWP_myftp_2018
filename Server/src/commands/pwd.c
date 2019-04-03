/*
** EPITECH PROJECT, 2018
** pwd.c
** File description:
** get current directorie
*/

#include "server.h"

void pwd_action(server_utils_t *utils,
        __attribute__((unused)) char *params,
        __attribute__((unused)) client_sks_t *client,
        __attribute__((unused)) int fd)
{
    send_client_message(fd, utils->pwd, 200);
}
