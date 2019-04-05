##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## Makefile
##

LIB_UTILS_DIR	=	../library/utils

INC	=	-I $(LIB_UTILS_DIR)/includes -I ../includes 

SRC_DIR	= ./sources/

SRCS	=	main.c

CFLAGS	=	-Wall -Wextra -g $(INC)

LDFLAGS	=	-lutils -L $(LIB_UTILS_DIR)

PREFIX_SRCS	= $(addprefix $(SRC_DIR), $(SRCS))

OBJS		=	$(PREFIX_SRCS:.c=.o)

NAME		=	client

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
