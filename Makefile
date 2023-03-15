# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kfaustin <kfaustin@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/03 10:31:26 by kfaustin          #+#    #+#              #
#    Updated: 2023/03/15 11:56:08 by kfaustin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

BINARY	= so_long
BINARYB	= so_long_bonus
LIBFTA	= libft.a
MINILBA	= libmlx_Linux.a
PRINTA	= libftprintf.a

CC		= cc
CFLAG	= -Wall -Wextra -Werror
LIB		= ar rcs
RM		= rm -f
MFLAG	= -lXext -lX11

# Mandatory
SRCDIR	= ./src/
SRC		= destroy.c event.c general.c general_a.c map.c move.c so_long.c validation.c validation_a.c validation_b.c
OBJ		= $(addprefix $(SRCDIR), $(SRC))
# Bonus
SRCBDIR	= ./bonus/
SRCB	= destroy_bonus.c enemy_bonus.c event_bonus.c general_bonus_a.c general_bonus.c map_bonus.c move_bonus.c so_long_bonus.c \
			validation_bonus_a.c validation_bonus_b.c validation_bonus.c
BOBJ	= $(addprefix $(SRCBDIR), $(SRCB))

all: libft minilibx ftprintf
	$(CC) $(CFLAG) $(OBJ) $(MINILBA) $(LIBFTA) $(PRINTA) -o $(BINARY) $(MFLAG) -g

bonus: libft minilibx ftprintf
	$(CC) $(CFLAG) $(BOBJ) $(MINILBA) $(LIBFTA) $(PRINTA) -o $(BINARYB) $(MFLAG) -g

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
	make clean -C ./includes/ft_printf

fclean: clean
	$(RM) $(LIBFTA) $(PRINTA) $(MINILBA) $(BINARY)
	$(RM) $(BINARY) $(BINARYB)

re: fclean all
