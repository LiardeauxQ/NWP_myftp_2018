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
