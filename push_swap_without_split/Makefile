
NAME = push_swap

CC = gcc

CFLAGS = -Werror -Wall -Wextra -fsanitize=address

RM = rm -rf

SRCS = 	check_valide.c\
		prepare_pa.c\
		prepare_pb.c\
		push_operations.c\
		push_swap.c\
		reverserotate_operations.c\
		rotate_operations.c\
		set_node.c\
		sort_stack.c\
		sort_utils.c\
		swap_operations.c\

$(NAME) :
	$(CC) $(CFLAGS) $(SRCS) -o $(NAME)

all : $(NAME)

fclean : clean
	$(RM) $(NAME)

clean :
	$(RM) $(NAME)

re : fclean all
