##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## Makefile
##

INC	=	-I ../inc

SRCDIR	= ./src/

SRCS	=	main.c	\
			main_socket.c	\
			init_connection.c	\
			client_sockets_management.c

CFLAGS	=	-Wall -Wextra -g $(INC)

LDFLAGS	=	-lutils -L ../lib/

PREFIX_SRCS	= $(addprefix $(SRCDIR), $(SRCS))

OBJS		=	$(PREFIX_SRCS:.c=.o)

NAME		=	myftp

all:	$(NAME)

$(NAME):	$(OBJS)
	@make --no-print-directory -C ../lib/
	@printf 'FLAGS: $(LDFLAGS) $(CFLAGS)\n'
	@printf 'Create: ./$(NAME)\n'
	@$(CC) -o $(NAME) $^ $(CFLAGS) $(LDFLAGS)

%.o:	%.c
	@printf '[OK] Building: $<\n'
	@$(CC) -o $@ -c $< $(LDFLAGS) $(CFLAGS)

clean:
	@make clean --no-print-directory -C ../lib/
	@rm -f $(OBJS)
	@printf 'Clean : OK\n'

fclean: clean
	@make fclean --no-print-directory -C ../lib/
	@rm -f $(NAME)
	@printf 'Fclean: ./$(NAME)\n'

re: fclean all

.PHONY: all clean fclean re
