/*
** EPITECH PROJECT, 2018
** pasv.c
** File description:
** pasv command
*/

#include "server.h"

void pasv_action(server_utils_t *utils, char *param,
        client_sks_t *client_info)
{
    sockinfo_t data = init_data_socket();

    client_info->data = data.socket;
    send_client_pasv_message(&data, client_info->control,
            "Entering Passive Mode", 227);
}
