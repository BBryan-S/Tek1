##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## Makefile
##

SRC	=	main.c				\
		set_struct.c		\
		print_help.c		\
		change_one.c		\
		change_two.c		\
		change_three.c		\
		print_debug.c		\
		get_tetriminos.c	\
		tool.c

NAME	=	tetris

CFLAGS	=	-Wall -Wextra -g3

CPPFLAGS	=	-I include

SRCDIR	=	./srcs/

OBJ	=	$(addprefix $(SRCDIR), $(SRC:.c=.o))

all:	$(NAME)

$(NAME):	$(OBJ)
	make -C lib/my
	gcc -o $(NAME) $(OBJ) $(LIB_GRAPHICS) -L lib/my -lmy -lcurses

clean:
	rm -f $(OBJ)
	make -C lib/my clean

fclean: clean
	make -C lib/my fclean
	rm -f $(NAME)
	rm -f *#	\
	rm -f *~

re:	fclean all

.PHONY: all clean re fclean
