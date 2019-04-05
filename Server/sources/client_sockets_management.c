/*
** EPITECH PROJECT, 2018
** client_sockets_managment.c
** File description:
** manage clients socket
*/

#include "server.h"

static void disconnect_client(const int client_socket)
{
    struct sockaddr_in skaddr;
    socklen_t addrlen = sizeof(struct sockaddr_in);

    getpeername(client_socket, (struct sockaddr*)&skaddr, &addrlen);
    printf("Host disconnected, %s:%d\n",
            inet_ntoa(skaddr.sin_addr), ntohs(skaddr.sin_port));
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
    printf("%s\n", client_cmd);
    fflush(stdout);
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
        send_client_message(client->control, 500);
    free_2d_char_array(split_cmd);
}

void check_sockets_event(fd_set *readfds,
        client_sks_t (*clients)[MAX_CLIENT],
        server_utils_t *utils)
{
    int fd = 0;
    char *buffer = NULL;

    for (int i = 0 ; i < MAX_CLIENT ; i++) {
        fd = (*clients)[i].control;
        if (!FD_ISSET(fd, readfds))
            continue;
        if ((buffer = get_next_line(fd)) == NULL) {
            disconnect_client(fd);
            (*clients)[i] = (client_sks_t){0, 0, 0};
        } else
            handle_client_command(buffer, utils, clients[i]);
        free(buffer);
    }
}
