SRCS =		$(SRC_DIR)/gnl/get_next_line_utils.c	\
			$(SRC_DIR)/gnl/get_next_line.c			\
			$(SRC_DIR)/main.c 						\
			$(SRC_DIR)/utils.c
CC = cc
CFLAGS= -Wextra -Werror -Wall
MLX_PATH = opengl
MLXFLAGS = -L$(MLX_PATH) -lmlx -framework OpenGL -framework AppKit
HEADER = include
OBJS = $(SRCS:.c=.o)
NAME = cub3d
LIB_NAME = libft.a
LIB_DIR = ./libft
SRC_DIR = ./sources

$(NAME): $(OBJS) $(MLX_LIB)
	$(MAKE) bonus -C $(LIB_DIR)/
	mv $(LIB_DIR)/$(LIB_NAME) $(LIB_NAME)
	$(CC) $(CFLAGS) $(MLXFLAGS) $(OBJS) $(LIB_NAME) -o $(NAME)

all : $(NAME)

clean :
	make clean -C $(LIB_DIR)/
	make clean -C $(MLX_PATH)/
	rm -rf $(OBJS)

fclean : clean
	rm -rf $(NAME) $(LIB_NAME)

re : fclean
	make all

.PHONY : clean fclean all re