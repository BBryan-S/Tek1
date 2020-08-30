##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## Makefile
##

SRC	=		main.c	\
			create_map.c	\
			get_next_line.c	\
			game.c	\
			player_turn.c	\
			get_params.c	\
			matches_left.c	\
			ai_turn.c

NAME	=	matchstick

CFLAGS	=	-Wall -Wextra -I include

SRCDIR	=	./srcs/

OBJ	=	$(addprefix $(SRCDIR), $(SRC:.c=.o))

all:    $(NAME)

$(NAME):        $(OBJ)
	make -C lib/my
	gcc -o $(NAME) $(OBJ) -L lib/my -lmy

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
