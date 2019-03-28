/*
** EPITECH PROJECT, 2018
** error.c
** File description:
** error handler
*/

#include "utils.h"

void check_malloc(void *value)
{
    if (value == NULL) {
        perror("malloc");
        exit(84);
    }
}
