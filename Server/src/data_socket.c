/*
** EPITECH PROJECT, 2018
** name
** File description:
** handle data socket connection
*/

#include "server.h"

sockinfo_t init_data_socket(void)
{
    sockinfo_t data = {0};
    int port = DEFAULT_PORT;

    while (port <= MAX_PORT) {
        data = init_socket(port++);
        if (data.socket != -1)
            break;
    }
    if (port >= MAX_PORT)
        handle_error("data socket error");
    return (data);
}

void successful_data_socket_connection(const sockinfo_t *data, const int fd)
{
    int p[2] = {0};

    p[0] = data->port / 256;
    p[1] = data->port % 256;
    dprintf(fd, "227 Entering Passive Mode (%d, %d, %d, %d, %d, %d)\n",
            data->ip.octet_1, data->ip.octet_2, data->ip.octet_3,
            data->ip.octet_4, p[0], p[1]);
}
