# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yson <yson@student.42seoul.kr>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/24 18:07:01 by kyujlee           #+#    #+#              #
#    Updated: 2022/06/16 18:18:44 by yson             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS =		$(SRC_DIR)/gnl/get_next_line.c			\
			$(SRC_DIR)/utils_2.c						\
			$(SRC_DIR)/cub3d.c \
	   		$(SRC_DIR)/parsing.c \
	   		$(SRC_DIR)/draw_background.c \
	   		$(SRC_DIR)/draw_wall.c \
	   		$(SRC_DIR)/draw_wall2.c \
	   		$(SRC_DIR)/check_map.c \
	   		$(SRC_DIR)/read_utils.c \
	   		$(SRC_DIR)/map_utils.c \
	   		$(SRC_DIR)/source_check.c \
	   		$(SRC_DIR)/convert_map.c \
	   		$(SRC_DIR)/init_game.c \
	   		$(SRC_DIR)/moving.c \
	   		$(SRC_DIR)/utils.c
CC = cc
# CFLAGS= -Wextra -Werror -Wall
CFLAGS= -g3 -fsanitize=address
MLX_PATH = opengl
MLXFLAGS = -L$(MLX_PATH) -lmlx -framework OpenGL -framework AppKit
HEADER = include
OBJS = $(SRCS:.c=.o)
NAME = cub3D
LIB_NAME = libft.a
LIB_DIR = ./libft
SRC_DIR = ./Src

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