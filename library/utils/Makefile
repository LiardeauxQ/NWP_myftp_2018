##
## EPITECH PROJECT, 2017
## Makefile
## File description:
## Makefile
##

SRC_DIR	=	sources/

SRCS	=	str_to_word_array.c	\
			count_2d_array.c	\
			get_next_line.c	\
			error.c	\
			free_memory.c	\
			clean_str.c	\
			get_ip.c

PREFIX_SRCS	=	$(addprefix $(SRC_DIR), $(SRCS))

OBJ	=	$(PREFIX_SRCS:.c=.o)

NAME	=	libutils.a

CFLAGS	=	-W -I ./includes

$(NAME):	$(OBJ)
	@echo -e 'Flags: $(CFLAGS)'
	@echo -e 'Create: $(NAME)'
	@ar rc $(NAME) $(OBJ)

%.o:	%.c
	@echo -e '[OK] Building : $<'
	@$(CC) -o $@ -c $< $(LDFLAGS) $(CFLAGS)

clean:
	@rm -f $(OBJ)
	@echo -e 'Clean : OK'

fclean: clean
	@rm -f $(NAME)
	@echo -e 'Fclean : OK'

re: fclean all

.PHONY: re fclean clean all
