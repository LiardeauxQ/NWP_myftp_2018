/*
** EPITECH PROJECT, 2018
** retr.c
** File description:
** RETR command
*/

#include <fcntl.h>
#include <sys/stat.h>
#include "server.h"

static char *read_file(const char *filename)
{
    int fd = 0;
    char *buffer = NULL;
    struct stat file_info = {0};

    if (stat(filename, &file_info))
        return (NULL);
    fd = open(filename, O_RDONLY);
    if (fd == -1)
        return (NULL);
    buffer = malloc(sizeof(char) * file_info.st_size);
    read(fd, buffer, file_info.st_size);
    close(fd);
    return (buffer);
}

static int handle_retr_command(const char *param, int control_sk, int data_sk)
{
    char **split_cmd = str_to_word_array(param, " \t");
    char *buffer = 0;

    if (count_2d_array(split_cmd) != 2)
        return (-1);
    buffer = read_file(split_cmd[1]);
    if (buffer == NULL)
        return (-1);
    send_client_code(control_sk, 150); 
    if (fork() == 0) {
        write(data_sk, buffer, strlen(buffer));
        free(buffer);
        free_2d_char_array(split_cmd);
        exit(0);
    }
    close(data_sk);
    return (0);
}

void retr_action(server_utils_t *utils, char *param,
        client_sks_t *client)
{
    if (client->is_connect != 2) {
        send_client_code(client->control, 530);
        return;
    }
    if (handle_retr_command(param, client->control, client->data)) {
        send_client_message(client->control, "Failed to open file.", 550);
        return;
    }
    send_client_code(client->control, 226);
}
