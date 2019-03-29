/*
** EPITECH PROJECT, 2018
** lib.h
** File description:
** lib header
*/

#ifndef LIB_H_
#	define LIB_H_

char **str_to_word_array(char const *str, char *c);

char *get_ip_address(void);

char *get_next_line(int fd);

void free_2d_int_array(int **array);
void free_2d_char_array(char **array);

#endif /* LIB_H_ */
