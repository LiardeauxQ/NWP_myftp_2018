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
    int skfd = socket(AF_INET, SOCK_STREAM, 0);

    memset(&sockaddr, 0, sizeof(struct sockaddr_in));
    if (skfd == -1)
        handle_error("socket");
    sockaddr.sin_family = AF_INET;
    sockaddr.sin_port = htons(port);
    sockaddr.sin_addr.s_addr = htons(INADDR_ANY);
    if (bind(skfd, (struct sockaddr *) &sockaddr,
                sizeof(struct sockaddr_in)) == -1)
        handle_error("bind");
    return (skfd);
}

int main(int __attribute__((unused)) ac, char **av)
{
    struct sockaddr_in acceptaddr;
    socklen_t addrlen = sizeof(struct sockaddr_in);
    int skfd = init_socket_connection(atoi(av[1]));
    int acfd = 0;

    if (listen(skfd, 50) == -1)
        handle_error("listen");
    while (1) {
        acfd = accept(skfd, (struct sockaddr *) &acceptaddr, &addrlen);
        if (acfd == -1)
            handle_error("accept");
        fprintf(stdout, "Connection from %s:%d\n",
                inet_ntoa(acceptaddr.sin_addr), ntohs(acceptaddr.sin_port));
        dprintf(acfd, "Hello world\n");
        close(acfd);
    }
    return (0);
}
