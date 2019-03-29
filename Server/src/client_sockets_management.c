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

void handle_client_command(const char *client_cmd)
{
    char **split_cmd = str_to_word_array(client_cmd, " \t");

    if (strcmp(split_cmd[0], "USER") == 0) {
    }
    if (strcmp(split_cmd[0], "PASS") == 0) {
    }
    if (strcmp(split_cmd[0], "PASV") == 0) {
    }
    if (strcmp(split_cmd[0], "RETR") == 0) {
    }
    free_2d_char_array(split_cmd);
}

void check_sockets_event(fd_set *readfds,
        int (*client_sockets)[MAX_CLIENT],
        server_utils_t *utils)
{
    int fd = 0;
    char *buffer = NULL;

    for (int i = 0 ; i < MAX_CLIENT ; i++) {
        fd = (*client_sockets)[i];
        if (!FD_ISSET(fd, readfds))
            continue;
        if ((buffer = get_next_line(fd)) == NULL) {
            disconnect_client(fd);
            (*client_sockets)[i] = 0;
        } else
            write(fd, buffer, strlen(buffer));
        free(buffer);
    }
}
