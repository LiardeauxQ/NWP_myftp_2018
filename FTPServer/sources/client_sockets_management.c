/*
** EPITECH PROJECT, 2018
** client_sockets_managment.c
** File description:
** manage clients socket
*/

#include "server.h"

static void disconnect_client(const int client_socket)
{
    printf("Close connection\n");
    close(client_socket);
}

void handle_client_command(char *client_cmd,
        server_utils_t *utils,
        client_sks_t *client)
{
    char **split_cmd = str_to_word_array(clean_str(client_cmd), " \t");
    int found = 0;

    if (split_cmd == NULL)
        return;
    for (int i = 0 ; cmd[i].name != NULL ; i++) {
        if (!strcmp(split_cmd[0], cmd[i].name)) {
            if (cmd[i].action != NULL) {
                cmd[i].action(utils, client_cmd, client);
                found = 1;
            }
            break;
        }
    }
    if (!found)
        send_client_code(client->control, 500);
    free_2d_char_array(split_cmd);
}

static void read_control_socket(server_utils_t *utils, client_sks_t *client)
{
    int i = 0;
    char *buffer = NULL;
    size_t size = 0;
    FILE *stream = fdopen(client->control, "r");

    while (getline(&buffer, &size, stream) != -1) {
        handle_client_command(buffer, utils, client);
        free(buffer);
        size = 0;
        i = i + 1;
    }
    if (i == 0) {
        disconnect_client(client->control);
        *client = (client_sks_t){0, 0, 0};
    }
    fclose(stream);
}

void check_sockets_event(fd_set *readfds,
        client_sks_t (*clients)[MAX_CLIENT],
        server_utils_t *utils)
{
    int fd = 0;

    for (int i = 0 ; i < MAX_CLIENT ; i++) {
        fd = (*clients)[i].control;
        if (!FD_ISSET(fd, readfds))
            continue;
        read_control_socket(utils, &((*clients)[i]));
    }
}
