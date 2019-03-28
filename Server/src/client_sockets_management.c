/*
** EPITECH PROJECT, 2018
** client_sockets_managment.c
** File description:
** manage clients socket
*/

#include "ftp.h"

void check_sockets_event(fd_set *readfds, int (*client_sockets)[MAX_CLIENT])
{
    int fd = 0;
    int size = 0;
    struct sockaddr_in skaddr;
    socklen_t addrlen = sizeof(struct sockaddr_in);
    char buffer[1024];

    for (int i = 0 ; i < MAX_CLIENT ; i++) {
        fd = (*client_sockets)[i];
        if (FD_ISSET(fd, readfds)) {
            if ((size = read(fd, buffer, 1024)) == 0) {
                getpeername(fd, (struct sockaddr*) &skaddr, &addrlen);
                printf("Host disconnected, %s:%d\n",
                        inet_ntoa(skaddr.sin_addr), ntohs(skaddr.sin_port));
                (*client_sockets)[i] = 0;
                close(fd);
            } else {
                buffer[size] = 0;
                write(fd, buffer, size);
            }
        }
    }
}
