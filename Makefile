# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kfaustin <kfaustin@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/03 10:31:26 by kfaustin          #+#    #+#              #
#    Updated: 2023/03/03 12:07:23 by kfaustin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

BINARY	= so_long
LIBFTA	= libft.a
GNLA	= get_next_line.a
MINILBA	= libmlx_Linux.a
SOLONGA = so_long.a

CC		= cc
CFLAG	= -Wall -Wextra -Werror
LIB		= ar rcs
RM		= rm -f
MFLAG	= -lX11 -lXext

SRCDIR	= ./src/
SRC		= so_long.c
OBJ		= $(addprefix $(SRCDIR), $(SRC:.c=.o))

all: libft gnl solong minilibx
	$(CC) $(CFLAG) $(SOLONGA) $(MFLAG) $(MINILBA) $(LIBFTA) $(GNLA) -o $(BINARY)

libft:
	make -C ./includes/libft
	mv ./includes/libft/$(LIBFTA) .

gnl:
	make -C ./includes/get_next_line
	mv ./includes/get_next_line/$(GNLA) .

minilibx:
	cp ./minilibx-linux/$(MINILBA) .

solong: $(OBJ)
	$(LIB) $(SOLONGA) $(OBJ)

clean:
	make clean -C ./includes/libft
	make clean -C ./includes/get_next_line
	$(RM) ./src/*.o

fclean:
	$(RM) $(LIBFTA) $(GNLA) $(MINILBA) $(SOLONGA) $(BINARY)
	make fclean -C ./includes/libft
	make fclean -C ./includes/get_next_line

re: fclean all
