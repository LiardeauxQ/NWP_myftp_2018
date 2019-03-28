/*
** EPITECH PROJECT, 2018
** ftp.h
** File description:
** ftp header
*/

#ifndef FTP_H_
#	define FTP_H_

#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

#define LISTEN_BACKLOG 50

#define EXIT_ERROR 84
#define MAX_CLIENT 30

#define handle_error(msg) \
	do { perror(msg); exit(EXIT_ERROR); } while (0)

#endif /* FTP_H_ */
