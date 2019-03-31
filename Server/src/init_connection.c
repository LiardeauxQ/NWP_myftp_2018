/*
** EPITECH PROJECT, 2018
** init_connection.c
** File description:
** init connection to server
*/

#include "server.h"

sockinfo_t init_socket(const int port)
{
    sockinfo_t info = {0};

    memset(&info, 0, sizeof(sockinfo_t));
    info.socket = socket(AF_INET, SOCK_STREAM, 0);
    if (info.socket == -1)
        return (info);
    info.port = port;
    info.sockaddr.sin_family = AF_INET;
    info.sockaddr.sin_port = htons(port);
    info.sockaddr.sin_addr.s_addr = htons(INADDR_ANY);
    if (bind(info.socket, (struct sockaddr *) &info.sockaddr,
             sizeof(struct sockaddr_in)) == -1) {
        info.socket = -1;
        return (info);
    }
    return (info);
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
