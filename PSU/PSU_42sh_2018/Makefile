##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## Makefile
##

SRC	=		main.c	\
			init_struct.c	\
			command_list.c	\
			command.c		\
			get_command.c	\
			tool.c			\
			set_env.c		\
			unset_env.c		\
			env_pwd.c		\
			exec_command.c		\
			get_type.c		\
			separator.c		\
			redirection.c		\
			red_tool.c		\
			my_parser.c		\
			input.c			\
			super_tool.c	\
			get_signal_error.c	\
			echo.c			\
			ls.c

NAME	=	42sh

CFLAGS	=	-Wall -Wextra -g3

CPPFLAGS	=	-I include

SRCDIR	=	./srcs/

OBJ	=	$(addprefix $(SRCDIR), $(SRC:.c=.o))

all:	$(NAME)

$(NAME):	$(OBJ)
	make -C lib/my
	gcc -o $(NAME) $(OBJ) -L lib/my -lmy

clean:
	rm -f $(OBJ)
	make -C lib/my clean

fclean:	clean
	make -C lib/my fclean
	rm -f $(NAME)
	rm -f *#	\
	rm -f *~

re:	fclean all

.PHONY: all clean re fclean
