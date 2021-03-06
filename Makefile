#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ada-cunh <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/02/18 01:09:31 by ada-cunh          #+#    #+#              #
#    Updated: 2017/02/28 02:40:15 by ada-cunh         ###   ########.fr        #
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
		srcs/projection.c \
		srcs/draw.c \
		srcs/color.c \

OBJ	=	$(SRC:srcs/%.c=%.o)

all: $(NAME)

$(NAME):
		make -C libft/
		make -C minilibx_macos/  
		gcc	$(FLAGS) $(I)-c $(SRC)
		gcc -o $(NAME) $(OBJ) $(L)

clean: 
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
