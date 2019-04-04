/*
** EPITECH PROJECT, 2018
** commands.c
** File description:
** manage commands
*/

#include "server.h"

const struct reply_code_s codes[] =
{
    {"File status okay; about to open data connection.", 150},
    {"Command successful.", 200},
    {"UNIX", 215},
    {"Service ready for new user.", 220},
    {"Service closing control connection.", 221},
    {"Closing data connection.", 226},
    {"Login successful.", 230},
    {"User name okay, need password.", 331},
    {"Need account for login.", 332},
    {"Command not found.", 665},
    {"Error", 666},
    {NULL, 0}
};
