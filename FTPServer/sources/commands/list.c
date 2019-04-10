/*
** EPITECH PROJECT, 2018
** list.c
** File description:
** LIST command
*/

#include "server.h"

void list_action(server_utils_t *utils, char *param,
        client_sks_t *client)
{
    int pid = 0;
    char **split_cmd = NULL;

    if (!client->is_connect) {
        send_client_code(client->control, 530);
        return;
    }
    send_client_code(client->control, 150);
    if ((pid = fork()) == 0) {
        split_cmd = str_to_word_array(param, " \t");
        free(split_cmd[0]);
        split_cmd[0] = strdup("ls");
        dup2(client->data, 1);
        execvp(split_cmd[0], split_cmd);
    }
    close(client->data);
    send_client_code(client->control, 226);
}
