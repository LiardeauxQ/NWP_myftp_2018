/*
** EPITECH PROJECT, 2018
** get_ip.c
** File description:
** get ip address
*/

#include <netdb.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include "utils.h"

char *get_ip_address(void)
{
    char host_buffer[256];
    struct hostent *host_entry;

    if (gethostname(host_buffer, sizeof(host_buffer)) == -1) {
        perror("gethostname");
        exit(84);
    }
    host_entry = gethostbyname(host_buffer);
    if (host_entry == NULL) {
        perror("gethostbyname");
        exit(84);
    }
    return (inet_ntoa(*((struct in_addr*)host_entry->h_addr_list[0])));
}
