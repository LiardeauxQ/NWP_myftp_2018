/*
** EPITECH PROJECT, 2018
** main_socket.c
** File description:
** main socket management
*/

#include "server.h"

void check_main_socket_event(fd_set *readfds,
        int (*client_sockets)[MAX_CLIENT], const int main_socket)
{
    struct sockaddr_in acceptaddr;
    socklen_t addrlen = sizeof(struct sockaddr_in);
    int new_socket = 0;

    if (!FD_ISSET(main_socket, readfds))
        return;
    new_socket = accept(main_socket, (struct sockaddr *) &acceptaddr,
            &addrlen);
    if (new_socket == -1)
        handle_error("accept");
    printf("Connection from %s:%d\n", inet_ntoa(acceptaddr.sin_addr),
            ntohs(acceptaddr.sin_port));
    for (int i = 0 ; i < MAX_CLIENT ; i++) {
        if ((*client_sockets)[i] == 0) {
            (*client_sockets)[i] = new_socket;
            break;
        }
    }
}
