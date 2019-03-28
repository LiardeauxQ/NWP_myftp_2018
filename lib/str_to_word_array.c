/*
** EPITECH PROJECT, 2017
** str_to_word_array.c
** File description:
** split str to array when there are seperators
*/

#include <stdlib.h>
#include <unistd.h>
#include <string.h>

static int check_same_caractere(char str, char *c)
{
	for (int i = 0 ; c[i] != '\0' ; i++) {
		if (c[i] == str)
			return (1);
	}
	return (0);
}

static int check_multiple_caractere(char *str, char *c, int i)
{
	while (str[i] != '\0' && (check_same_caractere(str[i], c) == 1))
		i = i + 1;
	return (i);
}

static int count_char_rec(char *str, char *c)
{
	int size = 1;

	for (size_t i = 0 ; i < strlen(str) ; i++) {
		if (check_same_caractere(str[i], c) == 1)
			size = size + 1;
		i = check_multiple_caractere(str, c, i);
	}
	return (size);
}

char **str_to_word_array(char const *str, char *c)
{
	char *tmp = strdup(str);
	char *saveptr = NULL;
	char *token = strtok_r(tmp, c, &saveptr);
	char **array = NULL;
	int size = 1;

	if (str == NULL)
		return (NULL);
	while (token != NULL) {
		array = realloc(array, (size + 1) * sizeof(char *));
		array[size - 1] = strdup(token);
		tmp = NULL;
		token = strtok_r(tmp, c, &saveptr);
		size = size + 1;
	}
	if (array != NULL)
		array[size - 1] = NULL;
	free(tmp);
	return (array);
}
