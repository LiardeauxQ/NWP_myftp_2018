##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## Makefile
##

INC	=	-I ../inc

SRCDIR	= ./src/

SRCS	=	main.c

CFLAGS	=	-Wall -Wextra -g $(INC)

PREFIX_SRCS	= $(addprefix $(SRCDIR), $(SRCS))

OBJS		=	$(PREFIX_SRCS:.c=.o)

NAME		=	client

all:	$(NAME)

$(NAME):	$(OBJS)
	@printf 'FLAGS: $(LDFLAGS) $(CFLAGS)\n'
	@printf 'Create: ./$(NAME)\n'
	@$(CC) -o $(NAME) $^ $(CFLAGS) $(LDFLAGS)

%.o:	%.c
	@printf '[OK] Building: $<\n'
	@$(CC) -o $@ -c $< $(LDFLAGS) $(CFLAGS)

clean:
	@rm -f $(OBJS)
	@printf 'Clean : OK\n'

fclean: clean
	@rm -f $(NAME)
	@printf 'Fclean: ./$(NAME)\n'

re: fclean all

.PHONY: all clean fclean re
