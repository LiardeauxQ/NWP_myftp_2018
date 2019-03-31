/*
** EPITECH PROJECT, 2018
** commands.c
** File description:
** manage commands
*/

#include "server.h"

const struct cmd_info_s cmd[] =
{
    {"USER", NULL},
    {"PASS", NULL},
    {"CWD", NULL},
    {"CDUP", NULL},
    {"QUIT", NULL},
    {"DELE", NULL},
    {"PWD", NULL},
    {"PASV", &pasv_action},
    {"PORT", NULL},
    {"HELP", NULL},
    {"NOOP", NULL},
    {"RETR", NULL},
    {"STOR", NULL},
    {"LIST", NULL},
    {NULL, NULL}
};
