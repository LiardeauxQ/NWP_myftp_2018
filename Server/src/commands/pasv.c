/*
** EPITECH PROJECT, 2018
** pasv.c
** File description:
** pasv command
*/

#include "server.h"

void pasv_action(server_utils_t *utils, char *param,
        client_sks_t *client_info, int fd)
{
    sockinfo_t data = init_data_socket();

    client_info->data = data.socket;
    successful_data_socket_connection(&data, fd);
}
