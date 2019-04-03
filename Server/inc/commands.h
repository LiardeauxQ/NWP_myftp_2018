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

extern const struct cmd_info_s cmd[];

/* pasv.c */

void pasv_action(server_utils_t *utils, char *param,
		client_sks_t *client_info, int fd);

/* cwd.c */

char *create_new_dir(const char *home, const char *str);
void cwd_action(server_utils_t *utils, char *param,
		client_sks_t *client_info, int fd);

/* pwd.c */

void pwd_action(server_utils_t *utils, char *param,
		client_sks_t *client_info, int fd);

/* user.c */

void user_action(server_utils_t *utils, char *param,
		client_sks_t *client_info, int fd);

/* pass.c */

void pass_action(server_utils_t *utils, char *param,
		client_sks_t *client_info, int fd);

#endif /* COMMANDS_H_ */
