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
    {"Directory status.", 212},
    {"File status.", 213},
    {"Help message.", 214},
    {"UNIX", 215},
    {"Service ready for new user.", 220},
    {"Service closing control connection.", 221},
    {"Closing data connection.", 226},
    {"Login successful.", 230},
    {"Requested file action okay, completed.", 250},
    {"User name okay, need password.", 331},
    {"Need account for login.", 332},
    {"Can't open data connection.", 425},
    {"Syntax error, command unrecognized.", 500},
    {"Syntax error in parameters or arguments.", 501},
    {"Command not implemented.", 502},
    {"Not logged in.", 530},
    {"Need account for storing files.", 532},
    {"Error", 666},
    {NULL, 0}
};
