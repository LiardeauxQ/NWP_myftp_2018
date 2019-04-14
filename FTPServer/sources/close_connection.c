/*
** EPITECH PROJECT, 2018
** close_connection.c
** File description:
** close server connection
*/

#include "server.h"

void close_server_connection(server_utils_t *utils)
{
    free(utils->home);
    free(utils->pwd);
    close(utils->control.socket);
}

void free_client(client_sks_t *client)
{
	client->is_connect = 0;
	client->control = 0;
	client->data = 0;
	client->pid = 0;
	free(client->username);
	client->username = NULL;
}
