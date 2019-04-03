/*
** EPITECH PROJECT, 2018
** commands.c
** File description:
** manage commands
*/

#include "server.h"

const struct cmd_info_s cmd[] =
{
    {"USER", &user_action},
    {"PASS", &pass_action},
    {"CWD", &cwd_action},
    {"CDUP", NULL},
    {"QUIT", NULL},
    {"DELE", NULL},
    {"PWD", &pwd_action},
    {"PASV", &pasv_action},
    {"PORT", NULL},
    {"HELP", NULL},
    {"NOOP", NULL},
    {"RETR", NULL},
    {"STOR", NULL},
    {"LIST", NULL},
    {NULL, NULL}
};
