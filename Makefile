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
PRINTA	= libftprintf.a

CC		= cc
CFLAG	= -Wall -Wextra -Werror
LIB		= ar rcs
RM		= rm -f
MFLAG	= -lXext -lX11

SRCDIR	= ./src/
SRC		= destroy.c event.c general.c general_a.c map.c move.c so_long.c validation.c validation_a.c validation_b.c
OBJ		= $(addprefix $(SRCDIR), $(SRC))

all: libft minilibx ftprintf
	$(CC) $(CFLAG) $(OBJ) $(MINILBA) $(LIBFTA) $(PRINTA) -o $(BINARY) $(MFLAG) -g

libft:
	make -C ./includes/libft
	mv ./includes/libft/$(LIBFTA) .

minilibx:
	cp ./minilibx-linux/$(MINILBA) .

ftprintf:
	make -C ./includes/ft_printf
	mv ./includes/ft_printf/$(PRINTA) .

clean:
	make clean -C ./includes/libft
	make clean -C ./includes/ft_print
	$(RM) ./src/*.o

fclean:
	$(RM) $(LIBFTA) $(PRINTA) $(MINILBA) $(BINARY)
	make fclean -C ./includes/libft
	make fclean -C ./includes/ft_printf

re: fclean all
