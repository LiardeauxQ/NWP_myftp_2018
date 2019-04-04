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
    struct sockaddr_in acceptaddr;
    socklen_t addrlen = sizeof(struct sockaddr_in);
    ip_address_t *ip = &utils->control.ip;
    int p[2] = {0};

    p[0] = utils->data.port / 256;
    p[1] = utils->data.port % 256;
    dprintf(client->control, "%d %s (%d,%d,%d,%d,%d,%d)\n", 227,
            "Entering passive mode", ip->octet_1, ip->octet_2, ip->octet_3,
            ip->octet_4, p[0], p[1]);
    client->data = accept(utils->data.socket, (struct sockaddr *) &acceptaddr,
            &addrlen);
    //client->pid = fork();
    /*if (client->pid == 0) {
        printf("0 pid\n");
        dprintf(client->data, "LS data\n");
        dprintf(client->control, "LS control\n");
        close(client->data);
    }*/
    //printf("it's okai, %d\n", client->pid);
    //close(utils->data.socket);
}
