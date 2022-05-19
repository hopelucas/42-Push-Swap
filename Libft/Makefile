CC		= gcc
CFLAGS	= -Werror -Wall -Wextra -c -g

NAME  = libft.a
SOURCES = ft_printf.c \
		printf_utils.c \
		hex.c \
		ft_isalpha.c \
		ft_isdigit.c \
		ft_isalnum.c \
		ft_isascii.c \
		ft_strndup.c \
		ft_isprint.c \
		ft_strlen.c \
		ft_strnlen.c \
		ft_memset.c \
		ft_bzero.c \
		ft_memcpy.c \
		ft_memmove.c \
		ft_strlcpy.c \
		ft_strlcat.c \
		ft_toupper.c \
		ft_tolower.c \
		ft_strchr.c \
		ft_strrchr.c \
		ft_strncmp.c \
		ft_memchr.c \
		ft_memcmp.c \
		ft_strnstr.c \
		ft_atoi.c \
		ft_calloc.c \
		ft_strdup.c \
		ft_isspace.c \
		ft_substr.c \
		ft_strjoin.c \
		ft_strtrim.c \
		ft_split.c \
		ft_itoa.c \
		ft_strmapi.c \
		ft_striteri.c \
		ft_putchar_fd.c \
		ft_putstr_fd.c \
		ft_putendl_fd.c \
		ft_putnbr_fd.c

BONUS 	= ft_lstnew.c \
		ft_lstadd_front.c \
		ft_lstsize.c \
		ft_lstlast.c \
		ft_lstadd_back.c \
		ft_lstclear.c \

HEADERS = ../includes/libft.h
OBJECTS = $(SOURCES:.c=.o)
OBJECTS_B = $(BONUS:.c=.o)

all: $(NAME)

$(NAME): $(OBJECTS)
	ar rcs $(NAME) $(OBJECTS)

$(dothemaking):
	$(CC) $(FLAGS) $(CFLAGS) -o $(NAME) $(OBJECTS) $(HEADERS)

bonus:  $(OBJECTS) $(OBJECTS_B)
		ar rcs $(NAME) $(OBJECTS) $(OBJECTS_B)

clean:
	rm -rf *.o

fclean: clean
	rm -rf $(NAME)
	echo "[INFO] Library [$(NAME) removed!"

#Re-make everything.
re:		fclean all
