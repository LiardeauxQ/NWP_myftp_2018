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

char *get_string_ip_address(void)
{
    char host_buffer[256];
    struct hostent *host_entry;

    if (gethostname(host_buffer, sizeof(host_buffer)) == -1)
        return (NULL);
    host_entry = gethostbyname(host_buffer);
    if (host_entry == NULL)
        return (NULL);
    return (inet_ntoa(*(struct in_addr*)host_entry->h_addr_list[0]));
}

ip_address_t get_ip_address(void)
{
    char *string_ip = get_string_ip_address();
    char **split_ip = str_to_word_array(string_ip, ".");
    ip_address_t ip_address = {0, 0, 0, 0};

    if (split_ip == NULL) {
        perror("get_ip_address");
        exit(84);
    }
    ip_address.octet_1 = atoi(split_ip[0]);
    ip_address.octet_2 = atoi(split_ip[1]);
    ip_address.octet_3 = atoi(split_ip[2]);
    ip_address.octet_4 = atoi(split_ip[3]);
    free_2d_char_array(split_ip);
    return (ip_address);
}
