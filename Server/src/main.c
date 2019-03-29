/*
** EPITECH PROJECT, 2018
** main.c
** File description:
** main server file
*/

#include "server.h"

void server_loop(int (*client_sockets)[MAX_CLIENT], server_utils_t *utils)
{
    int max_fd = 0;
    int data_socket = 0;
    fd_set readfds;

    while (1) {
        max_fd = set_fds(&readfds, *client_sockets, utils->control_socket);
        if (select(max_fd + 1, &readfds, NULL, NULL, NULL) == -1)
            handle_error("select");
        check_main_socket_event(&readfds, client_sockets,
                utils->control_socket);
        check_sockets_event(&readfds, client_sockets, utils);
    }
    close(data_socket);
}

int main(int ac, char **av)
{
    server_utils_t utils = {0};
    int client_sockets[MAX_CLIENT];

    if (ac <= 1)
        return (84);
    printf("%s\n", get_ip_address());
    utils.port = atoi(av[1]);
    utils.control_socket = init_socket(utils.port);
    for (int i = 0 ; i < MAX_CLIENT ; i++)
        client_sockets[i] = 0;
    if (listen(utils.control_socket, 50) == -1)
        handle_error("listen");
    server_loop(&client_sockets, &utils);
    close(utils.control_socket);
    return (0);
}
