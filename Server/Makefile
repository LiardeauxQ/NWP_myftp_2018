##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## Makefile
##

LIB_UTILS_DIR	=	../library/utils

INC	=	-I $(LIB_UTILS_DIR)/includes/ -I ../includes/ -I ./includes/ 

SRCDIR	= ./sources/

SRCS	=	main.c	\
			main_socket.c	\
			init_connection.c	\
			close_connection.c	\
			data_socket.c	\
			reply_codes.c	\
			commands.c	\
			client_msg.c	\
			commands/user.c	\
			commands/pass.c	\
			commands/cwd.c	\
			commands/cdup.c	\
			commands/quit.c	\
			commands/dele.c	\
			commands/pwd.c	\
			commands/pasv.c	\
			commands/port.c	\
			commands/help.c	\
			commands/noop.c	\
			commands/retr.c	\
			commands/stor.c	\
			commands/list.c	\
			commands/syst.c	\
			client_sockets_management.c

CFLAGS	=	-Wall -g $(INC)

LDFLAGS	=	-lutils -L $(LIB_UTILS_DIR)

PREFIX_SRCS	= $(addprefix $(SRCDIR), $(SRCS))

OBJS		=	$(PREFIX_SRCS:.c=.o)

NAME		=	myftp

all:	$(NAME)

$(NAME):	$(OBJS)
	@make --no-print-directory -C $(LIB_UTILS_DIR)
	@printf 'FLAGS: $(LDFLAGS) $(CFLAGS)\n'
	@printf 'Create: ./$(NAME)\n'
	@$(CC) -o $(NAME) $^ $(CFLAGS) $(LDFLAGS)

%.o:	%.c
	@printf '[OK] Building: $<\n'
	@$(CC) -o $@ -c $< $(LDFLAGS) $(CFLAGS)

clean:
	@make clean --no-print-directory -C $(LIB_UTILS_DIR)
	@rm -f $(OBJS)
	@printf 'Clean : OK\n'

fclean: clean
	@make fclean --no-print-directory -C $(LIB_UTILS_DIR)
	@rm -f $(NAME)
	@printf 'Fclean: ./$(NAME)\n'

re: fclean all

.PHONY: all clean fclean re
