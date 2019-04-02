/*
** EPITECH PROJECT, 2018
** main.c
** File description:
** main server file
*/

#include "server.h"

void server_loop(client_sks_t (*clients)[MAX_CLIENT], server_utils_t *utils)
{
    int max_fd = 0;
    fd_set readfds;

    while (1) {
        max_fd = set_fds(&readfds, *clients, utils->control.socket);
        if (select(max_fd + 1, &readfds, NULL, NULL, NULL) == -1)
            handle_error("select");
        check_main_socket_event(&readfds, clients,
                utils->control.socket);
        check_sockets_event(&readfds, clients, utils);
    }
    //close(data_socket);
}

int main(int ac, char **av)
{
    server_utils_t utils = {0};
    client_sks_t clients[MAX_CLIENT] = {0};

    if (ac <= 1)
        return (84);
    utils.control = init_socket(atoi(av[1]));
    if (utils.control.socket == -1)
        handle_error("control socket initialization");
    for (int i = 0 ; i < MAX_CLIENT ; i++)
        printf("%d %d\n", clients[i].control, clients[i].data);
    if (listen(utils.control.socket, 50) == -1)
        handle_error("listen");
    server_loop(&clients, &utils);
    close(utils.control.socket);
    return (0);
}
