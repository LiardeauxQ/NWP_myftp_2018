/*
** EPITECH PROJECT, 2018
** pasv.c
** File description:
** pasv command
*/

#include "server.h"

void pasv_action(server_utils_t *utils, char __attribute__((unused)) *param,
        client_sks_t *client)
{
    struct sockaddr_in acceptaddr = {0};
    socklen_t addrlen = sizeof(struct sockaddr_in);
    ip_address_t *ip = &utils->control.ip;
    int p[2] = {0};

    if (!client->is_connect) {
        send_client_code(client->control, 530);
        return;
    }
    p[0] = utils->data.port / 256;
    p[1] = utils->data.port % 256;
    dprintf(client->control, "%d %s (%d,%d,%d,%d,%d,%d)\n", 227,
            "Entering passive mode", ip->octet_1, ip->octet_2, ip->octet_3,
            ip->octet_4, p[0], p[1]);
    client->data = accept(utils->data.socket, (struct sockaddr *) &acceptaddr,
            &addrlen);
}
