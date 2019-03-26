/*
** EPITECH PROJECT, 2018
** main.c
** File description:
** main file
*/

#include "ftp.h"

void handle_error(char const *msg)
{
    fprintf(stderr, msg);
    exit(84);
}

int main(int __attribute__((unused)) ac, char **av)
{
    struct sockaddr_in sockaddr;
    struct sockaddr_in acceptaddr;
    socklen_t addrlen = sizeof(struct sockaddr_in);
    int skfd = socket(AF_INET, SOCK_STREAM, 0);
    int acfd = 0;

    memset(&sockaddr, 0, sizeof(struct sockaddr_in));
    memset(&acceptaddr, 0, sizeof(struct sockaddr_in));
    if (skfd == -1)
        handle_error("Unable to init socket\n");
    sockaddr.sin_family = AF_INET;
    sockaddr.sin_port = htons(atoi(av[1]));
    sockaddr.sin_addr.s_addr = htons(INADDR_ANY);
    if (bind(skfd, (struct sockaddr *) &sockaddr,
                sizeof(struct sockaddr_in)) == -1)
        handle_error("Error with bind function\n");
    if (listen(skfd, 50) == -1)
        handle_error("Unable to listen on socket skfd\n");
    acfd = accept(skfd, (struct sockaddr *) &acceptaddr, &addrlen);
    if (acfd == -1)
        handle_error("Error with accept function\n");
    fprintf(stdout, "Connection from %s:%d",
            inet_ntoa(acceptaddr.sin_addr), ntohs(acceptaddr.sin_port));
    dprintf(acfd, "Hello world\n");
    close(acfd);
    return (0);
}
