# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kfaustin <kfaustin@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/03 10:31:26 by kfaustin          #+#    #+#              #
#    Updated: 2023/03/05 17:21:17 by kfaustin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

BINARY	= so_long
LIBFTA	= libft.a
MINILBA	= libmlx_Linux.a
SOLONGA	= so_long.a

CC		= cc
CFLAG	= -Wall -Wextra -Werror
LIB		= ar rcs
RM		= rm -f
MFLAG	= -lXext -lX11

SRCDIR	= ./src/
SRC		= destroy.c event.c general.c map.c so_long.c validation.c
OBJ		= $(addprefix $(SRCDIR), $(SRC))

all: libft minilibx
	$(CC) $(CFLAG) $(OBJ) $(MINILBA) $(LIBFTA) -o $(BINARY) $(MFLAG) -g

libft:
	make -C ./includes/libft
	mv ./includes/libft/$(LIBFTA) .

minilibx:
	cp ./minilibx-linux/$(MINILBA) .

clean:
	make clean -C ./includes/libft
	make clean -C ./includes/get_next_line
	$(RM) ./src/*.o

fclean:
	$(RM) $(LIBFTA) $(GNLA) $(MINILBA) $(SOLONGA) $(BINARY)
	make fclean -C ./includes/libft
	make fclean -C ./includes/get_next_line

re: fclean all
