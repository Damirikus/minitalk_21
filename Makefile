NAME	= server

NAME2	= client

CFLAGS	= -Wall -Wextra -Werror

CC		= gcc

HEADER		= minitalk.h

SRCS	= server.c
SRCS2	= client.c

OBJS	= $(SRCS:.c=.o)
OBJS2	= $(SRCS2:.c=.o)

all: $(NAME2) $(NAME) 
%.o: 	%.c $(HEADER)
		$(CC) $(CFLAGS) -c $< -o $@

$(NAME):	$(OBJS) $(HEADER)
			$(MAKE) bonus -C ./libft
			$(MAKE) all -C ./libft
			cp libft/libft.a ./$(NAME)
			$(CC) $(OBJS) ./libft/libft.a -o ${NAME}

$(NAME2):	$(OBJS2) $(HEADER)
			$(MAKE) bonus -C ./libft
			$(MAKE) all -C ./libft
			cp libft/libft.a ./$(NAME2)
			$(CC) $(OBJS2) ./libft/libft.a -o ${NAME2}

clean:
	$(MAKE) clean -C ./libft
	-rm -rf $(OBJS) $(OBJS2)
	
fclean: clean
	$(MAKE) fclean -C ./libft
	-rm -rf $(NAME) $(NAME2)

re:		fclean all

.PHONY: all clean fclean re
