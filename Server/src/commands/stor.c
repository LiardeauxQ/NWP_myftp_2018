/*
** EPITECH PROJECT, 2018
** stor.c
** File description:
** STOR command
*/

#include <fcntl.h>
#include "server.h"

void stor_action(server_utils_t *utils, char *param,
        client_sks_t *client)
{
    int pid = 0;
    int fd = 0;
    char **split_cmd = str_to_word_array(param, " \t");
    
    if (count_2d_array(split_cmd) != 2) {
        send_client_message(client->control, 666);
        return;
    }
    fd = open(split_cmd[1], O_CREAT | O_RDWR);
    if (fd == -1) {
        send_client_message(client->control, 666);
        return;
    }
    dup2(fd, client->data);
    send_client_message(client->control, 150); 
    if ((pid = fork()) == 0) {
        exit(0);
    }
    close(client->data);
    send_client_message(client->control, 226);
}
