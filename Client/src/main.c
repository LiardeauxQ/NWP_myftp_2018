/*
** EPITECH PROJECT, 2018
** main.c
** File description:
** main client file
*/

#include "ftp.h"

int main(int __attribute__((unused)) ac, char **av)
{
    struct sockaddr_in sockaddr;
    int skfd = socket(AF_INET, SOCK_STREAM, 0);
    char buffer[500] = {0};

    memset(&sockaddr, 0, sizeof(struct sockaddr_in));
    if (skfd == -1)
        handle_error("Unable to init socket\n");
    sockaddr.sin_family = AF_INET;
    sockaddr.sin_port = htons(atoi(av[1]));
    sockaddr.sin_addr.s_addr = inet_addr("127.0.0.1");
    if (connect(skfd, (struct sockaddr *) &sockaddr,
                sizeof(struct sockaddr_in)) == -1)
        handle_error("Unable to connect\n");
    read(skfd, buffer, 500);
    printf("%s\n", buffer);
    close(skfd);
    return (0);
}
