/*
** EPITECH PROJECT, 2018
** server.h
** File description:
** server header
*/

#ifndef SERVER_H_
#    define SERVER_H_

#include "ftp.h"
#include "server_utils.h"
#include "commands.h"
#include "reply_codes.h"

#define MAX_IP_LENGTH 16

/* client_socket_management.c */

void check_sockets_event(fd_set *readfds,
    client_sks_t (*clients)[MAX_CLIENT], server_utils_t *utils);

/* data_socket.h */

sockinfo_t init_data_socket(void);
sockinfo_t init_master_socket(const int port);
void successful_data_socket_connection(const sockinfo_t *data, const int fd);

/* client_msg.c */

void send_client_code(const int fd, const int code);
void send_client_message(const int fd, const char *msg, const int code);

/* close_connection.c */

void close_server_connection(server_utils_t *utils);
void free_client(client_sks_t *client);

#endif /* SERVER_H_ */
