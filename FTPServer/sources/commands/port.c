/*
** EPITECH PROJECT, 2018
** port.c
** File description:
** PORT command
*/

#include "server.h"

static char *reform_ip_address(char **data)
{
    static char string_ip[MAX_IP_LENGTH] = {0};

    for (int i = 0 ; i < 4 ; i++) {
        if (i > 0)
            strcat(string_ip, ".");
        strcat(string_ip, data[i]);
    }
    return (string_ip);
}

static struct sockaddr_in init_sockaddr_in(const int sin_family,
        const int sin_port, const int s_addr)
{
    struct sockaddr_in sockaddr = {0};

    sockaddr.sin_family = sin_family;
    sockaddr.sin_port = sin_port;
    sockaddr.sin_addr.s_addr = s_addr;
    return (sockaddr);
}

static int handle_connection_to_client(char *param)
{
    char **params = str_to_word_array(param, " \t(),");
    struct sockaddr_in sockaddr = {0};
    int data_socket = 0;
    int opt = 1;

    if (params == NULL)
        return (-1);
    if (count_2d_array(params) != 7 ||
            (data_socket = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
        free_2d_char_array(params);
        return (-1);
    }
    setsockopt(data_socket, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt));
    sockaddr = init_sockaddr_in(AF_INET, htons(atoi(params[5]) * 256
            + atoi(params[6])), inet_addr(reform_ip_address(params + 1)));
    if (connect(data_socket, (struct sockaddr*)&sockaddr,
            sizeof(struct sockaddr_in)) == -1)
        data_socket = -2;
    free_2d_char_array(params);
    return (data_socket);
}

void port_action(server_utils_t *utils, char *param,
        client_sks_t *client)
{
    if (client->is_connect != 2) {
        send_client_code(client->control, 530);
        return;
    }
    client->data = handle_connection_to_client(param);
    switch (client->data) {
    case -1:
        send_client_code(client->control, 501);
        break;
    case -2:
        send_client_code(client->control, 530);
        break;
    default:
        send_client_code(client->control, 200);
        return;
    }
    client->data = 0;
}
