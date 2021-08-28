NAME = push_swap

SRCS =	commands/push.c			add_argv.c\
		commands/rotate.c		all_stuff.c\
		commands/swap.c			dup_check.c\
		commands/rrotate.c		errors.c\
		main.c					sort_small_stack.c\
		sort.c					

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