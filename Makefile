##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## Makefile
##

CLIENT_DIR	=	FTPClient/
SERVER_DIR	=	FTPServer/

CLIENT_NAME	=	client
SERVER_NAME	=	myftp

all:
	@printf "Starting client compilation:\n"
	@make --no-print-directory -C $(CLIENT_DIR)
	@mv $(CLIENT_DIR)$(CLIENT_NAME) .
	@printf "\nStarting server compilation:\n"
	@make --no-print-directory -C $(SERVER_DIR)
	@mv $(SERVER_DIR)$(SERVER_NAME) .

clean:
	@make clean --no-print-directory -C $(CLIENT_DIR)
	@make clean --no-print-directory -C $(SERVER_DIR)

fclean:
	@make fclean --no-print-directory -C $(CLIENT_DIR)
	@rm -f $(CLIENT_NAME)
	@make fclean --no-print-directory -C $(SERVER_DIR)
	@rm -f $(SERVER_NAME)

re: fclean all

.PHONY: all clean fclean re
