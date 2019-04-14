/*
** EPITECH PROJECT, 2018
** list.c
** File description:
** LIST command
*/

#include "server.h"

static char **check_list_options(const char *param)
{
    char **split_cmd = str_to_word_array(param, " \t");
    size_t size = count_2d_array(split_cmd);

    if (size < 1)
        return (NULL);
    free(split_cmd[0]);
    split_cmd[0] = strdup("ls");
    split_cmd = realloc(split_cmd, (size + 2) * sizeof(char*));
    for (int i = size ; i > 1 ; i--)
        split_cmd[i] = split_cmd[i - 1];
    split_cmd[1] = strdup("-l");
    split_cmd[size + 1] = NULL;
    return (split_cmd);
}

void list_action(server_utils_t *utils, char *param,
        client_sks_t *client)
{
    int pid = 0;
    char **split_cmd = NULL;

    if (client->is_connect != 2) {
        send_client_code(client->control, 530);
        return;
    }
    send_client_code(client->control, 150);
    split_cmd = check_list_options(param);
    if ((pid = fork()) == 0) {
        dup2(client->data, 1);
        execvp(split_cmd[0], split_cmd);
    }
    close(client->data);
    send_client_code(client->control, 226);
    free_2d_char_array(split_cmd);
}
