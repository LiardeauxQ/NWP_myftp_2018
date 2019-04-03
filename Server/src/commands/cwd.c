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
    new_dir = calloc(1, (strlen(str) + size + 1) * sizeof(char));
    strcat(new_dir, home);
    if (new_dir[size - 1] != 47) {
        new_dir[size] = 47;
        new_dir[size + 1] = 0;
    }
    strcat(new_dir, str);
    return (new_dir);
}

void cwd_action(server_utils_t *utils, char *param,
        client_sks_t __attribute__((unused)) *client_info, int fd)
{
    char **params = str_to_word_array(param, " \t");
    char *new_dir = NULL;

    if (count_2d_array(params) != 2) {
        send_client_message(fd, "ERROR", 666);
        return;
    }
    new_dir = create_new_dir(utils->pwd, params[1]);
    if (new_dir == NULL)
        return;
    if (chdir(new_dir)) { 
        send_client_message(fd, "Invalid new directory", 666);
        return;
    }
    free(utils->pwd);
    utils->pwd = getcwd(NULL, 0);
    free_2d_char_array(params);
    free(new_dir);
    send_client_message(fd, "Change working directory", 200);
}
