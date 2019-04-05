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

void port_action(server_utils_t *utils, char *param,
        client_sks_t *client)
{
    char **split_cmd = str_to_word_array(param, " \t(),");
    struct sockaddr_in sockaddr = {0};

    if (count_2d_array(split_cmd) != 7) {
        send_client_message(client->control, 501);
        return;
    }
    client->data = socket(AF_INET, SOCK_STREAM, 0);
    sockaddr.sin_family = AF_INET;
    sockaddr.sin_port = htons(atoi(split_cmd[5]) * 256 + atoi(split_cmd[6]));
    sockaddr.sin_addr.s_addr = inet_addr(reform_ip_address(split_cmd + 1));
    if (connect(client->data, (struct sockaddr *) &sockaddr,
            sizeof(struct sockaddr_in)) == -1) {
        client->data = 0;
        send_client_message(client->control, 666);
        return;
    }
    send_client_message(client->control, 200);
    free_2d_char_array(split_cmd);
}
