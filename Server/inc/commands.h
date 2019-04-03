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
    void (*action)(server_utils_t *, char *, client_sks_t*);
};

extern const struct cmd_info_s cmd[];

/* user.c */

void user_action(server_utils_t *utils, char *param,
		client_sks_t *client_info);

/* pass.c */

void pass_action(server_utils_t *utils, char *param,
		client_sks_t *client_info);

/* cwd.c */

char *create_new_dir(const char *home, const char *str);
void cwd_action(server_utils_t *utils, char *param,
		client_sks_t *client_info);

/* cdup.c */

void cdup_action(server_utils_t *utils, char *param,
		client_sks_t *client_info);

/* quit.c */

void quit_action(server_utils_t *utils, char *param,
		client_sks_t *client_info);

/* dele.c */

void dele_action(server_utils_t *utils, char *param,
		client_sks_t *client_info);

/* pwd.c */

void pwd_action(server_utils_t *utils, char *param,
		client_sks_t *client_info);

/* pasv.c */

void pasv_action(server_utils_t *utils, char *param,
		client_sks_t *client_info);

/* port.c */

void port_action(server_utils_t *utils, char *param,
		client_sks_t *client_info);

/* help.c */

void help_action(server_utils_t *utils, char *param,
		client_sks_t *client_info);

/* noop.c */

void noop_action(server_utils_t *utils, char *param,
		client_sks_t *client_info);

/* retr.c */

void retr_action(server_utils_t *utils, char *param,
		client_sks_t *client_info);

/* stor.c */

void stor_action(server_utils_t *utils, char *param,
		client_sks_t *client_info);

/* list.c */

void list_action(server_utils_t *utils, char *param,
		client_sks_t *client_info);

#endif /* COMMANDS_H_ */
