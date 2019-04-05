/*
** EPITECH PROJECT, 2018
** pass.c
** File description:
** PASS command
*/

#include "server.h"

void pass_action(server_utils_t __attribute__((unused)) *utils, char *param,
        client_sks_t __attribute__((unused)) *client_info)
{
    char **split_cmd = str_to_word_array(param, " \t");

    if (count_2d_array(split_cmd) == 1)
        send_client_message(client_info->control, 230);
    free_2d_char_array(split_cmd);
}