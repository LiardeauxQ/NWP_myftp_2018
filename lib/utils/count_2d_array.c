/*
** EPITECH PROJECT, 2018
** count_2d_array.c
** File description:
** count 2d array length
*/

#include "utils.h"

size_t count_2d_array(char **array)
{
    size_t size = 0;

    while (array[size++] != NULL);
    return (size);
}
