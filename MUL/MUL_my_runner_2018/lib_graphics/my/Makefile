##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## Makefile
##

SRC	=	create_my_window.c	\
		sprite_from_file.c

SRCDIR	=	./srcs/

OBJ	=	$(addprefix $(SRCDIR), $(SRC:.c=.o))

NAME	=	libmy.a

all:	$(NAME)

$(NAME):	$(OBJ)
	ar rc $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)	\
	rm -f *#	\
	rm -f *~	\

re: fclean all

.PHONY: all clean re fclean