/*
** EPITECH PROJECT, 2018
** user.c
** File description:
** USER command
*/

#include "server.h"

void user_action(server_utils_t __attribute__((unused)) *utils, char *param,
        client_sks_t *client)
{
    char **split_cmd = str_to_word_array(param, " \t");

    if (count_2d_array(split_cmd) == 2) {
        if (!strcmp("Anonymous", split_cmd[1])) {
            send_client_code(client->control, 331);
            client->is_connect = 1;
        } else
            send_client_code(client->control, 332);
    }
    free_2d_char_array(split_cmd);
}
