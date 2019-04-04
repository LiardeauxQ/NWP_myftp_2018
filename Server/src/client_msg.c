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
