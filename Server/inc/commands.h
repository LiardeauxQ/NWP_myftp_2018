/*
** EPITECH PROJECT, 2018
** commands.h
** File description:
** commands header
*/

#ifndef COMMANDS_H_
#	define COMMANDS_H_

#include "ftp.h"

struct cmd_info_s {
    char *name;
    void (*action)(server_utils_t *, char *, client_sks_t*, int);
};

/* pasv.c */

extern const struct cmd_info_s cmd[];

void pasv_action(server_utils_t *utils, char *param,
		client_sks_t *client_info, int fd);

#endif /* COMMANDS_H_ */
