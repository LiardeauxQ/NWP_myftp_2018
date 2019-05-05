/*
** EPITECH PROJECT, 2018
** clean_str.c
** File description:
** clean str
*/

#include "utils.h"

char *clean_str(char *str)
{
    char *tmp = str;
    int size = 0;

    for (int i = 0 ; tmp[i] != 0 && (tmp[i] <= 32 || tmp[i] >= 127) ; i++)
        str = str + 1;
    size = strlen(str) - 1;
    for (int i = size ; i >= 0 && (str[i] <= 32 || str[i] >= 127) ; i--)
        *(str + i) = 0;
    return (str);
}
