/*
** EPITECH PROJECT, 2018
** init_connection.c
** File description:
** init connection to server
*/

#include "server.h"

static void bind_socket(sockinfo_t *info, const int port)
{
    size_t struct_size = sizeof(struct sockaddr_in);
    struct sockaddr * sockaddr = (struct sockaddr *)&info->sockaddr;

    info->sockaddr.sin_family = AF_INET;
    info->sockaddr.sin_port = htons(port);
    info->sockaddr.sin_addr.s_addr = htons(INADDR_ANY);
    if (bind(info->socket, sockaddr, struct_size) == -1) {
        info->socket = -1;
        return;
    }
    info->ip = get_ip_address();
}

sockinfo_t init_master_socket(const int port)
{
    sockinfo_t info = {0};
    int option = 1;

    memset(&info, 0, sizeof(sockinfo_t));
    info.socket = socket(AF_INET, SOCK_STREAM, 0);
    if (info.socket == -1)
        return (info);
    setsockopt(info.socket, SOL_SOCKET, SO_REUSEADDR, &option, sizeof(int));
    bind_socket(&info, port);
    info.port = port;
    info.ip = get_ip_address();
    return (info);
}

sockinfo_t init_socket(const int port)
{
    sockinfo_t info = {0};

    memset(&info, 0, sizeof(sockinfo_t));
    info.socket = socket(AF_INET, SOCK_STREAM, 0);
    if (info.socket == -1)
        return (info);
    bind_socket(&info, port);
    info.port = port;
    return (info);
}

int set_fds(fd_set *readfds, const client_sks_t clients[MAX_CLIENT],
        const int sfd)
{
    int fd = 0;
    int max_fd = 0;

    FD_ZERO(readfds);
    FD_SET(sfd, readfds);
    max_fd = sfd;
    for (int i = 0 ; i < MAX_CLIENT ; i++) {
        fd = clients[i].control;
        if (fd > 0)
            FD_SET(fd, readfds);
        if (fd > max_fd)
            max_fd = fd;
    }
    return (max_fd);
}
