/*
** EPITECH PROJECT, 2018
** pasv.c
** File description:
** pasv command
*/

#include "server.h"

void pasv_action(server_utils_t *utils, char *param, int fd)
{
    utils->data = init_data_socket();
    successful_data_socket_connection(&utils->data, fd);
}
