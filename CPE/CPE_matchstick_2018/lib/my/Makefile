##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## Makefile
##

SRC	=	my_put_nbr.c		\
		my_strcat.c		\
		my_putstr.c		\
		my_show_word_array.c	\
		my_strcmp.c		\
		my_strlen.c		\
		my_putchar.c		\
		my_revstr.c		\
		my_strcpy.c		\
		my_alloc.c		\
		my_getnbr.c		\
		my_strdup.c

SRCDIR	=	./srcs/

OBJ	=	$(addprefix $(SRCDIR), $(SRC:.c=.o))

NAME	=	libmy.a

MYH	=	lib.h

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
