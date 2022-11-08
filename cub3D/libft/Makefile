NAME = libft.a

CC = gcc

CFLAGS = -Wall -Wextra -Werror

SRC = libft/ft_atoi.c \
	libft/ft_bzero.c \
	libft/ft_calloc.c \
	libft/ft_isalnum.c \
	libft/ft_isalpha.c \
	libft/ft_isascii.c \
	libft/ft_isdigit.c \
	libft/ft_isprint.c \
	libft/ft_itoa.c \
	libft/ft_utoa.c \
	libft/ft_xtoa.c \
	libft/ft_ptoa.c \
	libft/ft_otoa.c \
	libft/ft_lstadd_back.c \
	libft/ft_lstadd_front.c \
	libft/ft_lstclear.c \
	libft/ft_lstdelone.c \
	libft/ft_lstiter.c \
	libft/ft_lstlast.c \
	libft/ft_lstmap.c \
	libft/ft_lstnew.c \
	libft/ft_lstsize.c \
	libft/ft_memccpy.c \
	libft/ft_memchr.c \
	libft/ft_memcmp.c \
	libft/ft_memcpy.c \
	libft/ft_memmove.c \
	libft/ft_memset.c \
	libft/ft_max.c \
	libft/ft_min.c \
	libft/ft_putchar_fd.c \
	libft/ft_putendl_fd.c \
	libft/ft_putnbr_fd.c \
	libft/ft_putstr_fd.c \
	libft/ft_split.c \
	libft/ft_strchr.c \
	libft/ft_strcpy.c \
	libft/ft_strdup.c \
	libft/ft_strjoin.c \
	libft/ft_strlcat.c \
	libft/ft_strlcpy.c \
	libft/ft_strlen.c \
	libft/ft_strmapi.c \
	libft/ft_strncmp.c \
	libft/ft_strcmp.c \
	libft/ft_strnstr.c \
	libft/ft_strrchr.c \
	libft/ft_swap.c \
	libft/ft_strtrim.c \
	libft/ft_reverse.c \
	libft/ft_substr.c \
	libft/ft_tolower.c \
	libft/ft_toupper.c \
	libft/ft_abs.c \
	libft/malloc_free/ft_dyn_arr_free_char.c \
	libft/malloc_free/ft_dyn_arr_free_int.c \
	libft/malloc_free/ft_dyn_arr_mal_char.c \
	libft/malloc_free/ft_dyn_arr_mal_int.c \
	libft/malloc_free/ft_free_split.c \
	get_next_line/get_next_line.c

OBJS = $(patsubst %.c, %.o, $(SRC))
HEADERS = libft/libft.h get_next_line/get_next_line.h

%.o:		%.c $(HEADERS)
			$(CC) -c $(CFLAGS) $< -o $@

libft/%.o:	libft $(HEADERS)
			$(CC) -c $(CFLAGS) $< -o $@

$(NAME):	$(OBJS) $(HEADERS) Makefile
			ar rsc $(NAME) $(OBJS)

all:		$(NAME)

clean:
			rm -f $(OBJS)

fclean:		clean
			rm -f $(NAME)

re:			fclean all

.PHONY:		all clean fclean re
