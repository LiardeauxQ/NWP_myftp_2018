/*
** EPITECH PROJECT, 2018
** client_msg.c
** File description:
** send command message to client
*/

#include "server.h"

void send_client_message(const int fd, const int code)
{
    for (int i = 0 ; codes[i].msg != NULL ; i++) {
        if (codes[i].msg == code) {
            dprintf(fd, "%d %s\n", code, codes[i].msg);
            break;
        }
    }
}
