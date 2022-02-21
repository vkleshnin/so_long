SRCS	=	srcs/main.c srcs/pars_map.c srcs/check_valid_map.c srcs/ft_strlen.c srcs/ft_strdup.c srcs/ft_split.c\
			srcs/fill_window.c srcs/data_generate.c srcs/path_img.c srcs/player_move.c srcs/ft_lstnew.c\
			srcs/ft_lstlast.c srcs/ft_lstadd_back.c srcs/move_enemies.c srcs/ft_strncmp.c

NAME	=	so_long

CC		=	gcc

CFLAGS	=	-Wall -Wextra -Werror

MLX		=	-Lmlx -lmlx -framework OpenGL -framework AppKit

OBJS	=	${SRCS:.c=.o}

RM		=	rm -f

HEAD	=	includes/so_long.h

%.o:		%.c
			${CC} ${CFLAGS} -Imlx -c $< -o $@

${NAME}:	${OBJS} ${HEAD}
			@make -C ./mlx
			${CC} ${CFLAGS} ${MLX} ${OBJS} -o ${NAME}

all:		${NAME}
			${CC} ${CFLAGS} ${MLX} ${OBJS} -o ${NAME}
clean:
			${RM} ${OBJS}
			make clean -C ./mlx

fclean:		clean
			${RM} ${NAME}
			make clean -C ./mlx

re:         fclean all

.PHONY:		all clean fclean re