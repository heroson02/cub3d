# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kyujlee <kyujlee@student.42seoul.kr>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/24 18:07:01 by kyujlee           #+#    #+#              #
#    Updated: 2022/05/27 16:12:31 by kyujlee          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC= gcc

CFLAGS = -Wall -Wextra -Werror

SRCS = Src/raycasting.c \
	   Src/draw_background.c \
	   Src/draw_wall.c \
	   Src/draw_wall2.c \
	   Src/init_game.c \
	   Src/moving.c \
	   Src/utils.c \

SRCS_OBJS = $(SRCS:.c=.o)


.PHONY: all
all : cub3D

#$(CFLAGS)
%.o : %.c
	@$(CC) -c $< -o $@

cub3D : $(SRCS_OBJS)
	@$(CC)  -lmlx -framework opengl -framework appkit -o cub3D $^
	@echo "complete making execute file"

.PHONY: clean
clean :
	@rm -rf Src/*.o

.PHONY: fclean
fclean : clean
	@rm -rf cub3D
	@echo "clean object file and execute file"

.PHONY: re
re : fclean all