/*
** EPITECH PROJECT, 2018
** server.h
** File description:
** server header
*/

#ifndef SERVER_H_
#	define SERVER_H_

#include "ftp.h"
#include "server_utils.h"
#include "commands.h"

/* client_socket_management.c */

void check_sockets_event(fd_set *readfds,
		         int (*client_sockets)[MAX_CLIENT],
			 server_utils_t *utils);

/* data_socket.h */

sockinfo_t init_data_socket(void);
void successful_data_socket_connection(const sockinfo_t *data, const int fd);

#endif /* SERVER_H_ */
