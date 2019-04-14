/*
** EPITECH PROJECT, 2018
** server_utils.h
** File description:
** server utils structure
*/

#ifndef SERVER_UTILS_H_
#    define SERVER_UTILS_H_

typedef struct server_utils_s {
    char *home;
    char *pwd;
    sockinfo_t control;
    sockinfo_t data;
} server_utils_t;

#endif /* SERVER_UTILS_H_ */
