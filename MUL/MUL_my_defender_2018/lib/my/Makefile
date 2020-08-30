##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## Makefile
##

SRC	=	my_strcat.c			\
		my_strncmp.c			\
		my_strcmp.c			\
		my_strncpy.c			\
		my_strcpy.c			\
		my_putchar.c			\
		my_strdup.c			\
		my_str_to_word_array.c		\
		my_put_nbr_base.c		\
		my_strupcase.c			\
		my_put_nbr.c			\
		my_putstr.c			\
		my_strlen.c			\
		my_strlowcase.c			\
		my_strncat.c			\
		is_alphanum.c			\
		mem_alloc_2d_array.c		\
		fs_get_number_from_first_line.c	\
		my_getnbr.c			\
		load_file_in_mem.c		\
		my_alloc.c			\
		my_itoa.c			\
		my_revstr.c			\
		str_to_array.c			\
		array_change.c			\

OBJ	=	$(SRC:.c=.o)

NAME	=	libmy.a

HEAD	=	my.h

all:	$(NAME)

$(NAME):	$(OBJ)
	ar rc $(NAME) $(OBJ)
	make clean

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)
	rm -f ../$(NAME)

re:	fclean all
