NAME	= push_swap

CFLAGS	= -Wall -Wextra -Werror

CC		= gcc

HEADER		= push_swap.h

SRCS	= main.c ft_algorithm.c ft_algorithm_3.c ft_algorithm_5.c ft_actions.c ft_actions_next.c\
			ft_for_main_algorithm.c ft_instructions.c ft_instructions_next.c \
			ft_markup.c ft_works_with_array.c

OBJS	= $(SRCS:.c=.o)
%.o: 	%.c $(HEADER)
		$(CC) $(CFLAGS) -c $< -o $@

$(NAME):	$(OBJS) $(HEADER)
			$(MAKE) bonus -C ./libft
			$(MAKE) all -C ./libft
			cp libft/libft.a ./$(NAME)
			$(CC) $(OBJS) ./libft/libft.a -o ${NAME}

all: $(NAME)

clean:
	$(MAKE) clean -C ./libft
	-rm -rf $(OBJS)

fclean: clean
	$(MAKE) fclean -C ./libft
	-rm -rf $(NAME)

re:		fclean all

.PHONY: all clean fclean re
