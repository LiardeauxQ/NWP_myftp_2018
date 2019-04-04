/*
** EPITECH PROJECT, 2018
** main_socket.c
** File description:
** main socket management
*/

#include "server.h"

static ip_address_t split_ip_address(const struct in_addr *in)
{
    char *ip_string = inet_ntoa(*in);
    char **split_ip = str_to_word_array(ip_string, ".");
    ip_address_t ip_address = {0};

    ip_address.octet_1 = atoi(split_ip[0]);
    ip_address.octet_2 = atoi(split_ip[1]);
    ip_address.octet_3 = atoi(split_ip[2]);
    ip_address.octet_4 = atoi(split_ip[3]);
    free_2d_char_array(split_ip);
    return (ip_address);
}

void check_main_socket_event(fd_set *readfds,
        client_sks_t (*clients)[MAX_CLIENT], const int main_socket)
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
    send_client_message(new_socket, "Service ready for new user.", 220);
    for (int i = 0 ; i < MAX_CLIENT ; i++) {
        if ((*clients)[i].control == 0) {
            (*clients)[i].control = new_socket;
            break;
        }
    }
}
