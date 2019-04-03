/*
** EPITECH PROJECT, 2018
** client_msg.c
** File description:
** send command message to client
*/

#include "server.h"

void send_client_message(const int fd, const char *msg, const int code)
{
    dprintf(fd, "%d %s\n", code, msg);
}

void send_client_pasv_message(const sockinfo_t *data, const int fd,
        const char *msg, const int code)
{
    int p[2] = {0};

    p[0] = data->port / 256;
    p[1] = data->port % 256;
    dprintf(fd, "%d %s (%d, %d, %d, %d, %d, %d)\n", code, msg,
            data->ip.octet_1, data->ip.octet_2, data->ip.octet_3,
            data->ip.octet_4, p[0], p[1]);
}

