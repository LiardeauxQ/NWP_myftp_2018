/*
** EPITECH PROJECT, 2018
** main.c
** File description:
** main server file
*/

#include "ftp.h"

void server_loop(int (*client_sockets)[MAX_CLIENT],
        const int control_socket,
        const int port)
{
    int max_fd = 0;
    int data_socket = 0;
    fd_set readfds;

    while (1) {
        max_fd = set_fds(&readfds, *client_sockets, control_socket);
        if (select(max_fd + 1, &readfds, NULL, NULL, NULL) == -1)
            handle_error("select");
        check_main_socket_event(&readfds, client_sockets, control_socket);
        check_sockets_event(&readfds, client_sockets);
    }
    close(data_socket);
}

int main(int ac, char **av)
{
    int control_socket = 0;
    int client_sockets[MAX_CLIENT];
    int port = 0;

    if (ac <= 1)
        return (84);
    port = atoi(av[1]);
    control_socket = init_socket(port);
    for (int i = 0 ; i < MAX_CLIENT ; i++)
        client_sockets[i] = 0;
    if (listen(control_socket, 50) == -1)
        handle_error("listen");
    server_loop(&client_sockets, control_socket, port);
    close(control_socket);
    return (0);
}
