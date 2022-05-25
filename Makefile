# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kyujlee <kyujlee@student.42seoul.kr>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/24 18:07:01 by kyujlee           #+#    #+#              #
#    Updated: 2022/05/25 15:40:34 by kyujlee          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = Src/raycasting.c

SRCS_OBJS = $(SRCS:.c=.o)


.PHONY: all
all : cub3D
#-Wall -Wextra -Werror
%.o : %.c
	gcc   -c $<
	mv *.o Src

cub3D : $(SRCS_OBJS)
	gcc -fsanitize=address -lmlx -framework opengl -framework appkit -o cub3D $^

.PHONY: clean
clean :
	rm -rf Src/*.o

.PHONY: fclean
fclean : clean
	rm -rf cub3D

.PHONY: re
re : fclean all