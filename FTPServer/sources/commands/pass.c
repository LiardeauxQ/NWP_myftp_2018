/*
** EPITECH PROJECT, 2018
** pass.c
** File description:
** PASS command
*/

#include "server.h"

void pass_action(server_utils_t __attribute__((unused)) *utils, char *param,
        client_sks_t __attribute__((unused)) *client)
{
    char **split_cmd = str_to_word_array(param, " \t");

    if (!client->is_connect)
        send_client_code(client->control, 530);
    else if (count_2d_array(split_cmd) == 1
                && !strcmp(client->username, "Anonymous")) {
        send_client_code(client->control, 230);
	client->is_connect = 2;
    } else
        send_client_code(client->control, 332);
    free_2d_char_array(split_cmd);
}
