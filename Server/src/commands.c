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
    {"CDUP", &cdup_action},
    {"QUIT", &quit_action},
    {"DELE", &dele_action},
    {"PWD", &pwd_action},
    {"PASV", &pasv_action},
    {"PORT", &port_action},
    {"HELP", &help_action},
    {"NOOP", &noop_action},
    {"RETR", &retr_action},
    {"STOR", &stor_action},
    {"LIST", &list_action},
    {NULL, NULL}
};
