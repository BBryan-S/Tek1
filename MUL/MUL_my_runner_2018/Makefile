##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## Makefile
##

SRC	=	main.c	\
		struct_create.c	\
		display.c	\
		my_event.c	\
		player_init.c	\
		set_player_position.c	\
		jump_player.c	\
		my_cmp.c	\
		usage.c	\
		music.c

NAME	=	my_runner

CFLAGS	=	-Wall -Wextra -I include

LIB_GRAPHICS	=	-l csfml-graphics -l csfml-system -l csfml-window -l csfml-audio

SRCDIR	=	./srcs/

OBJ	=	$(addprefix $(SRCDIR), $(SRC:.c=.o))

all:	$(NAME)

$(NAME):	$(OBJ)
	make -C lib_graphics/my
	gcc -o $(NAME) $(OBJ) $(LIB_GRAPHICS) -L lib_graphics/my -lmy

clean:
	rm -f $(OBJ)
	make -C lib_graphics/my clean

fclean: clean
	make -C lib_graphics/my fclean
	rm -f $(NAME)
	rm -f *#	\
	rm -f *~

re:	fclean all

.PHONY: all clean re fclean