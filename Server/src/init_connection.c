/*
** EPITECH PROJECT, 2018
** init_connection.c
** File description:
** init connection to server
*/

#include "ftp.h"

int init_socket_connection(const int port)
{
    struct sockaddr_in sockaddr;
    int sfd = socket(AF_INET, SOCK_STREAM, 0);

    memset(&sockaddr, 0, sizeof(struct sockaddr_in));
    if (sfd == -1)
        handle_error("socket");
    sockaddr.sin_family = AF_INET;
    sockaddr.sin_port = htons(port);
    sockaddr.sin_addr.s_addr = htons(INADDR_ANY);
    if (bind(sfd, (struct sockaddr *) &sockaddr,
                sizeof(struct sockaddr_in)) == -1)
        handle_error("bind");
    return (sfd);
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
