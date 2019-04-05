/*
** EPITECH PROJECT, 2018
** ftp.h
** File description:
** ftp header
*/

#ifndef FTP_H_
#	define FTP_H_

#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include "utils.h"

#define LISTEN_BACKLOG 50

#define EXIT_ERROR 84
#define MAX_CLIENT 30

#define MAX_PORT 5000
#define DEFAULT_PORT 1024

#define handle_error(msg) \
	do { perror(msg); exit(EXIT_ERROR); } while (0)

typedef struct socket_info_s {
    int socket;
    int port;
    ip_address_t ip;
    struct sockaddr_in sockaddr;
} sockinfo_t;

typedef struct client_sockets_s {
    int control;
    int data;
    int pid;
} client_sks_t;

/* main_socket.c */

void check_main_socket_event(fd_set *readfds,
        client_sks_t (*clients)[MAX_CLIENT], const int main_socket);

/* init_connection.c */

sockinfo_t init_socket(const int port);
int set_fds(fd_set *readfds, const client_sks_t clients[MAX_CLIENT],
        const int sfd);

#endif /* FTP_H_ */
