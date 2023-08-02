# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mapoirie <mapoirie@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/13 11:08:06 by mapoirie          #+#    #+#              #
#    Updated: 2023/08/02 11:18:48 by mapoirie         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
CC = cc
RM = rm -fr
SRC = so_long.c\
so_long_utils.c\
read_map.c\
check_error.c\
check_error2.c\
check_error_utils.c\
check_error3.c\
get_next_line.c\
get_next_line_utils.c\
init_map.c\
init_img.c\
init_img_perso.c\
draw_img.c\
img_utils.c\
img_utils_sprite.c\
movement.c\
movement2.c\
count_move.c\
sprite.c\
sprite_utils.c\

OBJ = $(SRC:.c=.o)

$(NAME): $(OBJ)
#	cc -o $(NAME) $(OBJ)
	$(CC) $(OBJ) -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -o $(NAME)

all : $(NAME)

%.o : %.c
#	$(CC) -I $(CFLAGS) -o $@ -c $< 
	$(CC) -Wall -Wextra -Werror -g -I/usr/include -Imlx_linux -O3 -c $< -o $@


clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean 
	make all

.PHONY: all clean fclean re

# @make -s -C libft all 
#     @make -s -C minilibx-linux all 
#     @$(CC) $(PREFO) ./libft/libft.a ./minilibx-linux/libmlx.a -lX11 -lXext -o so_long
#     @echo "Terminé!"