# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alohashc <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/03/06 10:48:43 by alohashc          #+#    #+#              #
#    Updated: 2017/03/06 11:35:17 by alohashc         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

SRC = ./find_coordinates.c \
	  ./image.c \
	  ./window.c \
	  ./draw_file.c \
	  ./center.c \
	  ./events.c \
	  ./ft_create_line.c \
	  ./validation.c

O_FILE = $(SRC:.c=.o)

INC = ./

FLAGS = -Wall -Werror -Wextra

all: $(NAME)

$(NAME): $(O_FILE)
	make -C ./libft/
	gcc -o $(NAME) $(O_FILE) -L ./libft/ -lft -lmlx -framework OpenGL -framework AppKit

%.o: %.c
	gcc $(FLAGS) -I $(INC) -c $< 

clean:
	make clean -C ./libft/
	rm -rf $(O_FILE)

fclean: clean
	make fclean -C ./libft/
	rm -rf $(NAME)

re: clean all
