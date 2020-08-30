##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## Makefile
##

SRC	=	main.c	\
		read_file.c	\
		display_usage.c	\
		check_map.c	\
		my_game.c	\
		utilities.c	\
		move.c	\
		set_map.c

NAME	=	my_sokoban

CFLAGS	=	-Wall -Wextra

SRCDIR	=	./srcs/

OBJ	=	$(addprefix $(SRCDIR), $(SRC:.c=.o))

all:    $(NAME)

$(NAME):        $(OBJ)
	make -C lib/my
	gcc -o $(NAME) $(OBJ) -L lib/my -lmy -lcurses

clean:
	rm -f $(OBJ)
	make -C lib/my clean

fclean: clean
	make -C lib/my fclean
	rm -f $(NAME)
	rm -f *#	\
	rm -f *~

re:     fclean all

.PHONY: all clean re fclean
