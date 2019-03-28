/*
** EPITECH PROJECT, 2018
** main.c
** File description:
** main server file
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
