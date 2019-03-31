/*
** EPITECH PROJECT, 2018
** clean_str.c
** File description:
** clean str
*/

#include "utils.h"

char *clean_str(char *str)
{
    for (int i = 0 ; str[i] != 0 && (str[i] <= 32 || str[i] >= 127) ; i++)
        str = str + 1;
    for (int i = strlen(str) - 1 ;
            i >= 0 && (str[i] <= 32 || str[i] >= 127) ; i--)
        *(str + i) = 0;
    return (str);
}
