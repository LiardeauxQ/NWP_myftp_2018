/*
** EPITECH PROJECT, 2018
** server.h
** File description:
** server header
*/

#ifndef SERVER_H_
#	define SERVER_H_

#include "ftp.h"
#include "utils.h"

typedef struct server_utils_s {
    sockinfo_t control;
    sockinfo_t data;
} server_utils_t;

/* client_socket_management.c */

void check_sockets_event(fd_set *readfds,
		         int (*client_sockets)[MAX_CLIENT],
			 server_utils_t *utils);

/* data_socket.h */

sockinfo_t init_data_socket(void);

#endif
