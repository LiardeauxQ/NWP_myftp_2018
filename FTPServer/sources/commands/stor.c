/*
** EPITECH PROJECT, 2018
** stor.c
** File description:
** STOR command
*/

#include <fcntl.h>
#include "server.h"

static int handle_stor_command(const char *param, int control_sk, int data_sk)
{
    char **split_cmd = str_to_word_array(param, " \t");
    int fd = 0;

    if (count_2d_array(split_cmd) != 2)
        return (-1);
    fd = open(split_cmd[1], O_CREAT | O_RDWR);
    if (fd == -1)
        return (-1);
    dup2(fd, data_sk);
    send_client_code(control_sk, 150);
    if (fork() == 0)
        exit(0);
    close(fd);
    close(data_sk);
    return (0);
}

void stor_action(server_utils_t *utils, char *param,
        client_sks_t *client)
{
    if (client->is_connect != 2) {
        send_client_code(client->control, 530);
        return;
    }
    if (handle_stor_command(param, client->control, client->data)) {
        send_client_code(client->control, 666);
        return;
    }
    send_client_code(client->control, 226);
}
