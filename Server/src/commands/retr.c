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
        handle_error("stat");
    fd = open(filename, O_RDONLY);
    if (fd == -1)
        return (NULL);
    buffer = malloc(sizeof(char) * file_info.st_size);
    read(fd, buffer, file_info.st_size);
    close(fd);
    return (buffer);
}

void retr_action(server_utils_t *utils, char *param,
        client_sks_t *client)
{
    int pid = 0;
    char *buffer = 0;
    char **split_cmd = str_to_word_array(param, " \t");
    
    if (count_2d_array(split_cmd) != 2) {
        send_client_message(client->control, 666);
        return;
    }
    buffer = read_file(split_cmd[1]);
    if (buffer == NULL) {
        send_client_message(client->control, 666);
        return;
    }
    send_client_message(client->control, 150); 
    if ((pid = fork()) == 0) {
        write(client->data, buffer, strlen(buffer));
        free(buffer);
        free_2d_char_array(split_cmd);
        exit(0);
    }
    close(client->data);
    send_client_message(client->control, 226);
}
