#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ada-cunh <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/02/18 01:09:31 by ada-cunh          #+#    #+#              #
#    Updated: 2017/02/25 07:15:56 by ada-cunh         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = fdf

FLAGS	= -Wall -Wextra -Werror -g -O3

I = -I./includes \
	-I./libft/includes \

L = 	-L./libft/ -lft -L./minilibx_macos/ -lmlx -framework OpenGL -framework AppKit \

SRC	=	srcs/error.c \
		srcs/init.c \
		srcs/parser.c \
		srcs/main.c \
		srcs/hooks.c \
		srcs/color.c \
		srcs/projection.c \
		srcs/draw.c \

OBJ	=	$(SRC:srcs/%.c=%.o)

all: $(NAME)

$(NAME):
		make -C libft/
		make -C minilibx_macos/  
		gcc	$(FLAGS) $(I)-c $(SRC)
		gcc -o $(NAME) $(OBJ) $(L)

clean: 
	make -C libft/
	rm -f $(OBJ)

fclean: clean
	make -C ./libft fclean
	rm -f $(NAME)
	make -C minilibx_macos/

re: fclean all

.PHONY: all clean fclean re
