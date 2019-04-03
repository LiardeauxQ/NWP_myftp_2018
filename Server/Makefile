##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## Makefile
##

LIBUTILSDIR	=	../lib/utils/

INC	=	-I $(LIBUTILSDIR) -I ../inc -I ./inc/ 

SRCDIR	= ./src/

SRCS	=	main.c	\
			main_socket.c	\
			init_connection.c	\
			close_connection.c	\
			data_socket.c	\
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
			client_sockets_management.c

CFLAGS	=	-Wall -Wextra -g $(INC)

LDFLAGS	=	-lutils -L $(LIBUTILSDIR)

PREFIX_SRCS	= $(addprefix $(SRCDIR), $(SRCS))

OBJS		=	$(PREFIX_SRCS:.c=.o)

NAME		=	myftp

all:	$(NAME)

$(NAME):	$(OBJS)
	@make --no-print-directory -C $(LIBUTILSDIR)
	@printf 'FLAGS: $(LDFLAGS) $(CFLAGS)\n'
	@printf 'Create: ./$(NAME)\n'
	@$(CC) -o $(NAME) $^ $(CFLAGS) $(LDFLAGS)

%.o:	%.c
	@printf '[OK] Building: $<\n'
	@$(CC) -o $@ -c $< $(LDFLAGS) $(CFLAGS)

clean:
	@make clean --no-print-directory -C $(LIBUTILSDIR)
	@rm -f $(OBJS)
	@printf 'Clean : OK\n'

fclean: clean
	@make fclean --no-print-directory -C $(LIBUTILSDIR)
	@rm -f $(NAME)
	@printf 'Fclean: ./$(NAME)\n'

re: fclean all

.PHONY: all clean fclean re
