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

static int check_special_case(char**split_cmd)
{
    if (!strcmp(split_cmd[0], "QUIT"))
        return (1);
    return (0);
}

int handle_client_command(char *client_cmd,
        server_utils_t *utils,
        client_sks_t *client)
{
    char **split_cmd = str_to_word_array(clean_str(client_cmd), " \t");
    int found = 0;
    int quit = 0;

    for (int i = 0 ; split_cmd != NULL && cmd[i].name != NULL
            && quit == 0 ; i++) {
        if (!strcmp(split_cmd[0], cmd[i].name)) {
            if (cmd[i].action != NULL) {
                cmd[i].action(utils, client_cmd, client);
                found = 1;
            }
       quit = check_special_case(split_cmd);
            break;
        }
    }
    if (!found && !quit && strlen(client_cmd) > 0)
        send_client_code(client->control, 500);
    free_2d_char_array(split_cmd);
    return (quit);
}

static void read_control_socket(server_utils_t *utils, client_sks_t *client)
{
    int i = 0;
    char *buffer = NULL;

    while ((buffer = get_next_line(client->control)) != NULL) {
        if (handle_client_command(buffer, utils, client)) {
        free(buffer);
        break;
    }
        free(buffer);
        i = i + 1;
    }
    if (i == 0) {
        disconnect_client(client->control);
    free_client(client);
    }
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
