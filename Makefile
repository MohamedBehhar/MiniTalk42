NAME1	= server

NAME2	= client

CC		= gcc

CFLAGS	= -Wall -Werror -Wextra

LIBFT	= ./libft/libft.a

SERVER	= ./src/server.c

CLIENT	= ./src/client.c


all: 
	@make clean -C libft
	@make -C libft
	@$(CC) $(CFLAGS) $(LIBFT) $(SERVER) -o $(NAME1)
	@$(CC) $(CFLAGS) $(LIBFT) $(CLIENT) -o $(NAME2)

clean:
	@make clean -C libft
	@rm -rf $(NAME1)
	@rm -rf $(NAME2)

fclean: clean
	@make fclean -C libft

re: fclean all

