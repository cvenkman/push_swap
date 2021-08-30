NAME = push_swap

SRCS =	commands/push.c			src/add_argv.c\
		commands/rotate.c		src/stuff.c\
		commands/swap.c			src/dup_check.c\
		commands/rrotate.c		src/errors.c\
		main.c					src/sort_small_stack.c\
		src/sort_order.c				solve.c

OBJS = $(SRCS:.c=.o)

HEADER = push_swap.h

all : $(NAME)

$(NAME) : $(OBJS) $(HEADER)
	$(MAKE) -C libft
	$(CC) $(OBJS) $(CFLAGS) libft/libft.a -o $(NAME)

clean:
	$(MAKE) clean -C libft
	$(RM) $(OBJS)

fclean : clean
	$(MAKE) fclean -C libft
	$(RM) $(NAME)

re : fclean all

.PHONY: clean fclean re all