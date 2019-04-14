/*
** EPITECH PROJECT, 2018
** stor.c
** File description:
** STOR command
*/

#include <fcntl.h>
#include "server.h"

static char *read_data_socket(const int fd)
{
    char *buffer = malloc(1 * sizeof(char));
    char *line = NULL;
    size_t size = 0;

    if (buffer == NULL)
        return (NULL);
    buffer[0] = '\0';
    while ((line = get_next_line(fd)) != NULL) {
        size += strlen(line) + 2;
        buffer = realloc(buffer, size * sizeof(char));
	if (buffer == NULL)
            return (NULL);
	strcat(buffer, line);
	buffer[strlen(buffer) - 1] = '\n';
	buffer[strlen(buffer)] = '\0';
        free(line);
    }
    return (buffer);
}

static int handle_stor_command(const char *param, int control_sk, int data_sk)
{
    char **split_cmd = str_to_word_array(param, " \t");
    int fd = 0;
    char *buffer = NULL;

    if (count_2d_array(split_cmd) != 2)
        return (-1);
    fd = open(split_cmd[1], O_CREAT | O_WRONLY, 0666);
    if (fd == -1)
        return (-1);
    send_client_code(control_sk, 150);
    if (fork() == 0) {
	buffer = read_data_socket(data_sk);
	if (buffer == NULL)
            exit(0);
	write(fd, buffer, strlen(buffer));
	free(buffer);
        exit(0);
    }
    close(fd);
    return (0);
}

void stor_action(server_utils_t *utils, char *param,
        client_sks_t *client)
{
    if (client->is_connect != 2) {
        send_client_code(client->control, 530);
        return;
    }
    if (handle_stor_command(param, client->control, client->data)) {
        send_client_code(client->control, 666);
        return;
    }
    close(client->data);
    send_client_code(client->control, 226);
}
