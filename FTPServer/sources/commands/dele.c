/*
** EPITECH PROJECT, 2018
** dele.c
** File description:
** DELE command
*/

#include "server.h"

static int handle_dele_command(char *param, char *pwd)
{
    char **split_cmd = str_to_word_array(param, " \t");
    char *filename = NULL;

    if (count_2d_array(split_cmd) != 2)
        return (1);
    filename = create_new_dir(pwd, split_cmd[1]);
    free_2d_char_array(split_cmd);
    if (filename == NULL && remove(filename))
        return (1);
    free(filename);
    return (0);
}

void dele_action(server_utils_t *utils, char *param,
        client_sks_t *client)
{
    if (client->is_connect != 2) {
        send_client_code(client->control, 530);
        return;
    }
    if (handle_dele_command(param, utils->pwd)) {
        send_client_code(client->control, 550);
        return;
    }
    send_client_code(client->control, 250);
}
