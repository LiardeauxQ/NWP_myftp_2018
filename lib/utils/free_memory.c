/*
** EPITECH PROJECT, 2018
** name
** File description:
** free memory functions
*/

#include "utils.h"

void free_2d_int_array(int **array)
{
    for (int i = 0 ; array[i] != NULL ; i++)
        free(array[i]);
    free(array);
}

void free_2d_char_array(char **array)
{
    for (int i = 0 ; array[i] != NULL ; i++)
        free(array[i]);
    free(array);
}
