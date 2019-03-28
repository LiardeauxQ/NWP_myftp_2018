/*
** EPITECH PROJECT, 2018
** main.c
** File description:
** main server file
*/

#include "ftp.h"

int main(int __attribute__((unused)) ac, char **av)
{
    int sfd = init_socket_connection(atoi(av[1]));
    int max_fd = 0;
    int afd = 0;
    int client_sockets[MAX_CLIENT];
    fd_set readfds;

    for (int i = 0 ; i < MAX_CLIENT ; i++)
        client_sockets[i] = 0;
    if (listen(sfd, 50) == -1)
        handle_error("listen");
    while (1) {
        max_fd = set_fds(&readfds, client_sockets, sfd);
        afd = select(max_fd + 1, &readfds, NULL, NULL, NULL);
        if (afd == -1)
            handle_error("select");
        check_main_socket_event(&readfds, &client_sockets, sfd);
        check_sockets_event(&readfds, &client_sockets);
    }
    close(sfd);
    return (0);
}
