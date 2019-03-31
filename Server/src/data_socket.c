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

    while (port++ <= MAX_PORT) {
        data = init_socket(port);
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
    char **ip = str_to_word_array(inet_ntoa(data->sockaddr.sin_addr), ".");

    if (count_2d_array(ip) != 4) {
        free_2d_char_array(ip);
        return;
    }
    p[0] = data->port / 256;
    p[1] = data->port % 256;
    dprintf(fd, "227 Entering Passive Mode (%s, %s, %s, %s, %d, %d)",
            ip[0], ip[1], ip[2], ip[3], p[0], p[1]);
    free_2d_char_array(ip);
}
