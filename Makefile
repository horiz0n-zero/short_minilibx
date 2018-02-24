# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: afeuerst <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/02/24 15:30:25 by afeuerst          #+#    #+#              #
#    Updated: 2018/02/24 17:00:10 by afeuerst         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = short_minilibx.a
SRC = ./short_minilibx_init.c \
	  ./short_minilibx_deinit.c \
	  ./short_minilibx_data.c 

OBJ = $(SRC:.c=.o)
LIBX = ./minilibx_macos/libmlx.a

all: $(NAME)

$(NAME): $(LIBX) $(OBJ)
	ar -r $(NAME) $(OBJ)
	ranlib $(NAME)

$(LIBX):
	make -C ./minilibx_macos/

%.o: %.c
	clang ./minilibx_macos/libmlx.a -c $^ -o $@ -I ./minilibx_macos/

clean:
	rm $(OBJ)
	make -C ./minilibx_macos/ clean

fclean: clean
	rm $(NAME)

re: fclean all
