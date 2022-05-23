NAME = push_swap
#CFLAGS = -g
CFLAGS = -Wall -Wextra -Werror -g
SRC = src/instructions1.c src/instructions2.c src/instructions3.c src/list.c src/push_swap.c src/sort.c src/sort_utils.c src/error_handling.c src/median.c src/sort_huge.c
INCLUDES = ./includes/
LIBFT = ./libft/
LIBFT_A = ./libft/libft.a
OBJECTS = $(SRC:.c=.o)


all: $(NAME)


$(NAME): $(OBJECTS)

	make -C $(LIBFT) bonus
	gcc $(CFLAGS) -o $(NAME) $(OBJECTS) $(LIBFT_A)

clean:
	make clean -C $(LIBFT)
	rm -rf $(OBJS)
	rm -rf src/*.o

fclean: clean
	rm -rf $(NAME)

re: fclean all

test: all
	./push_swap 1 2 3


