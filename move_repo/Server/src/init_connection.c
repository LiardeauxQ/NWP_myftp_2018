/*
** EPITECH PROJECT, 2018
** init_connection.c
** File description:
** init connection to server
*/

#include "server.h"

int init_socket(const int port)
{
    struct sockaddr_in sockaddr;
    int fd = socket(AF_INET, SOCK_STREAM, 0);

    if (fd == -1)
        handle_error("socket");
    memset(&sockaddr, 0, sizeof(struct sockaddr_in));
    sockaddr.sin_family = AF_INET;
    sockaddr.sin_port = htons(port);
    sockaddr.sin_addr.s_addr = htons(INADDR_ANY);
    if (bind(fd, (struct sockaddr *) &sockaddr,
                sizeof(struct sockaddr_in)) == -1)
        handle_error("bind");
    return (fd);
}

int set_fds(fd_set *readfds, const int client_sockets[MAX_CLIENT],
        const int sfd)
{
    int fd = 0;
    int max_fd = 0;

    FD_ZERO(readfds);
    FD_SET(sfd, readfds);
    max_fd = sfd;
    for (int i = 0 ; i < MAX_CLIENT ; i++) {
        fd = client_sockets[i];
        if (fd > 0)
            FD_SET(fd, readfds);
        if (fd > max_fd)
            max_fd = fd;
    }
    return (max_fd);
}
