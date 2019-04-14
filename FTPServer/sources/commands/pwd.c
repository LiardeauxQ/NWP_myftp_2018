/*
** EPITECH PROJECT, 2018
** pwd.c
** File description:
** get current directorie
*/

#include "server.h"

char *get_current_dir_name(void);

void pwd_action(server_utils_t *utils,
        __attribute__((unused)) char *params,
        __attribute__((unused)) client_sks_t *client)
{
    char *pwd = NULL;

    if (client->is_connect != 2) {
        send_client_code(client->control, 530);
        return;
    }
    pwd = get_current_dir_name();
    dprintf(client->control, "257 %s created.\n", pwd);
    free(pwd);
}
