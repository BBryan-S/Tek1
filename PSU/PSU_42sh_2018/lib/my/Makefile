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
		my_str_to_word_array.c	\
		my_strcmp.c		\
		my_strlen.c		\
		my_putchar.c		\
		my_revstr.c		\
		my_strcpy.c		\
		my_alloc.c		\
		my_getnbr.c		\
		my_strdup.c		\
		my_stdarg.c		\
		my_printf.c		\
		prepare_my_unsigned.c	\
		my_put_nbr_base.c		\
		prepare_my_put_pointer.c	\
		my_put_shortnbr.c	\
		my_put_longnbr.c	\
		flags_ss.c		\
		get_next_line.c		\
		my_strncmp.c		\

SRCDIR	=	./srcs/

OBJ	=	$(addprefix $(SRCDIR), $(SRC:.c=.o))

CFLAGS	=	-Wall -Wextra -I include

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
