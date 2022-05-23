SRCS =		$(SRC_DIR)/gnl/get_next_line_utils.c	\
			$(SRC_DIR)/gnl/get_next_line.c			\
			$(SRC_DIR)/main.c 						\
			$(SRC_DIR)/utils.c
CC = cc
CFLAGS= -Wextra -Werror -Wall
HEADER = include
OBJS = $(SRCS:.c=.o)
NAME = cub3d
LIB_NAME = libft.a
LIB_DIR = ./libft
SRC_DIR = ./sources

$(NAME): $(OBJS)
	$(MAKE) bonus -C $(LIB_DIR)/
	mv $(LIB_DIR)/$(LIB_NAME) $(LIB_NAME)
	$(CC) $(CFLAGS) $(OBJS) $(LIB_NAME) -o $(NAME)

all : $(NAME)

clean :
	make clean -C $(LIB_DIR)/
	rm -rf $(OBJ)

fclean : clean
	rm -rf $(NAME) $(LIB_NAME)

re : fclean
	make all

.PHONY : clean fclean all re