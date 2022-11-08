NAME		=	cub3D

SRCS_DIR	=	src/

SRC			=	main/cub3d.c \
				main/cub_init.c \
				main/cub_hook.c \
				drawing/cub_draw.c \
				drawing/cub_draw_wall.c \
				drawing/cub_draw_wall2.c \
				drawing/cub_draw_minimap.c \
				moving/update_move.c \
				parsing/parsing.c \
				parsing/parsing_texture.c \
				parsing/parsing_texture_main.c \
				parsing/parsing_read_map.c \
				parsing/parsing_read_line.c \
				parsing/parsing_list_to_array.c \
				parsing/parsing_check_map_surrounding.c

OBJS		=	${addprefix ${SRCS_DIR}, ${SRC:.c=.o}}

HEADER		= 	include/cub3d.h

CC			=	gcc
CFLAGS		=	-Wall -Wextra -Werror

LIBFT_LIB	=	libft.a
LIBFT_DIR	=	./libft/
LIBFT		=	${LIBFT_DIR}${LIBFT_LIB}

MLX_LIB		=	libmlx.a
MLX_DIR		=	./mlx/
MLX_INC		=	-I ${MLX_DIR}
MLX			=	-framework OpenGL -framework AppKit

RM			=	rm -f

%.o			:	%.c	${HEADER}
				${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

${NAME}		:	${OBJS} ${HEADER} Makefile
				make all -C ./mlx
				@echo "Compiling..." [ $(MLX_LIB) ] SUCCESS
				@make -C ${LIBFT_DIR} all
				@echo "Compiling..." [ $(LIBFT_LIB) ] SUCCESS
				${CC} ${OBJS} -o ${NAME} ${LIBFT} ${MLX} ./mlx/libmlx.a
				@echo "Compiling..." [ $(NAME) ] SUCCESS

all 		:	$(NAME)

bonus		:	$(NAME)

clean:
				@make -C ${LIBFT_DIR} clean
				@echo "Cleaning..." [ $(LIBFT_LIB) ] SUCCESS
				@${RM} $(OBJS)
				@echo "Cleaning..." [ $(NAME) ] SUCCESS

fclean:
				@make -C ${LIBFT_DIR} fclean
				@${RM} ./mlx/libmlx.a
				@${RM} $(OBJS) $(NAME)
				@echo "Deleting..." [ $(NAME) ] SUCCESS

re: 			fclean all

.PHONY: 		all re clean fclean bonus
