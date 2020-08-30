##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## Makefile
##

SRC	=	main.c	\
		configuration/configure.c	\
		configuration/configure_tool.c	\
		configuration/error.c		\
		configuration/preparation.c	\
		configuration/map.c		\
		configuration/timer.c		\
		configuration/set_rect.c	\
		configuration/entity.c		\
		configuration/sound.c		\
		menu/display_menu.c		\
		menu/menu.c			\
		menu/tool.c			\
		menu/option_menu.c		\
		menu/game_menu.c		\
		menu/game_panel.c		\
		menu/tower_menu.c		\
		menu/upgrade_castle.c		\
		menu/upgrade.c			\
		menu/up_tool.c			\
		menu/upgrade_tower.c		\
		menu/info.c			\
		menu/misc.c			\
		game/game.c			\
		game/display_sprite.c		\
		game/data_operation.c		\
		game/display_tower.c		\
		game/display_info.c		\
		game/monster.c			\
		game/monster_list.c		\
		game/display_monster.c		\
		game/damage.c			\
		game/attack.c			\

NAME	=	my_defender

CFLAGS	=	 -I include

LIB_GRAPHICS	=	-l csfml-graphics -l csfml-system -l csfml-window -l csfml-audio

SRCDIR	=	./srcs/

OBJ	=	$(addprefix $(SRCDIR), $(SRC:.c=.o))

all:	$(NAME)

$(NAME):	$(OBJ)
	make -C lib/my
	gcc -o $(NAME) $(OBJ) $(LIB_GRAPHICS) -L lib/my -lmy

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
