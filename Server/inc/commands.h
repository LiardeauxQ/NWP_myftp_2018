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
    void (*action)(server_utils_t *, char *, int);
};

/* pasv.c */

extern const struct cmd_info_s cmd[];

void pasv_action(server_utils_t *utils, char *param, int fd);

#endif /* COMMANDS_H_ */
