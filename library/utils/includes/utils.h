/*
** EPITECH PROJECT, 2018
** utils.h
** File description:
** utils libs header
*/

#ifndef UTILS_H_
#    define UTILS_H_

#ifndef READ_SIZE
#	define READ_SIZE (50)
#endif /* READ_SIZE */

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>

typedef struct ip_address_s {
    short octet_1;
    short octet_2;
    short octet_3;
    short octet_4;
} ip_address_t;

/* error.c */

void check_malloc(void *value);

/* str_to_word_array.c */

char **str_to_word_array(char const *str, char *s);

/* count_2d_array.c */

size_t count_2d_array(char **array);

/* free_memory.c */

void free_2d_int_array(int **array);
void free_2d_char_array(char **array);

/* get_ip.c */

ip_address_t get_ip_address(void);

/* get_next_line.c */

char *get_next_line(int fd);

/* clean_str.c */

char *clean_str(char *clean_str);

#endif /* UTILS_H_ */
