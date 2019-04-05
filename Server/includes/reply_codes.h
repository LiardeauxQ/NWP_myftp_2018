/*
** EPITECH PROJECT, 2018
** reply_codes.h
** File description:
** reply codes message
*/

#ifndef REPLY_CODES_H_
#	define REPLY_CODES_H_

struct reply_code_s {
    char *msg;
    unsigned short code;
};

extern const struct reply_code_s codes[];

#endif /* REPLY_CODES_H_ */
