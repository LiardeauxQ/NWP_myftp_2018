/*
** EPITECH PROJECT, 2018
** name
** File description:
** change working directory
*/

#include "server.h"

char *create_new_dir(const char *home, const char *str)
{
    char *new_dir = NULL;
    size_t size = 0;

    if (home == NULL || str == NULL)
        return (NULL);
    if (str[0] == '/')
        return (strdup(str));
    size = strlen(home);
    new_dir = calloc(1, (strlen(str) + size + 2) * sizeof(char));
    strcat(new_dir, home);
    if (new_dir[size - 1] != 47) {
        new_dir[size] = 47;
        new_dir[size + 1] = 0;
    }
    strcat(new_dir, str);
    return (new_dir);
}

static int handle_cwd_command(char *param, char *pwd)
{
    char **split_cmd = str_to_word_array(param, " \t");
    char *new_dir = NULL;

    if (count_2d_array(split_cmd) != 2)
        return (1);
    new_dir = create_new_dir(pwd, split_cmd[1]);
    free_2d_char_array(split_cmd);
    if (new_dir == NULL || chdir(new_dir))
        return (1);
    free(new_dir);
    return (0);
}

void cwd_action(server_utils_t *utils, char *param,
        client_sks_t *client)
{
    if (client->is_connect != 2) {
        send_client_code(client->control, 530);
        return;
    }
    if (handle_cwd_command(param, utils->pwd)) {
        send_client_code(client->control, 501);
        return;
    }
    free(utils->pwd);
    utils->pwd = getcwd(NULL, 0);
    send_client_code(client->control, 200);
}
