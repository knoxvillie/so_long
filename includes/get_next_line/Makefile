#--- Compile and Shell scripts ---#
CC		= cc
CFLAGS	= -Wall -Wextra -Werror
LIB		= ar rcs
RM		= rm -f

#--- Program ---#
NAME	= get_next_line.a
SRC		= get_next_line.c get_next_line_utils.c get_next_line_bonus.c
OBJ		= $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(LIB) $(NAME) $(OBJ)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re:	fclean all
