##
## EPITECH PROJECT, 2017
## Makefile
## File description:
## Makefile
##

SRCLIB	=	str_to_word_array.c	\
			get_next_line.c	\
			error.c	\
			get_ip.c

OBJLIB	=	$(SRCLIB:.c=.o)

NAMELIB	=	libutils.a

CFLAGS	=	-W -I .

$(NAMELIB):	$(OBJLIB)
	@echo -e 'Flags: $(CFLAGS)'
	@echo -e 'Create: $(NAMELIB)'
	@ar rc $(NAMELIB) $(OBJLIB)

%.o:	%.c
	@echo -e '[OK] Building : $<'
	@$(CC) -o $@ -c $< $(LDFLAGS) $(CFLAGS)

clean:
	@rm -f $(OBJLIB)
	@echo -e 'Clean : OK'

fclean: clean
	@rm -f $(NAMELIB)
	@echo -e 'Fclean : OK'

re: fclean all

.PHONY: re fclean clean all
