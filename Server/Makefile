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
			data_socket.c	\
			commands.c	\
			commands/pasv.c	\
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
