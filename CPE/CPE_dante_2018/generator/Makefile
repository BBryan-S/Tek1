##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## Makefile
##

SRC	=		main.c	\
			get_info.c	\
			display.c	\
			generator.c	\
			tools.c		\
			branch.c	\

NAME	=	generator

CFLAGS	=	-Wall -Wextra

CPPFLAGS	=	-I ../include

SRCDIR	+=	./srcs/

OBJ	=	$(addprefix $(SRCDIR), $(SRC:.c=.o))

all:	$(NAME)

$(NAME):	$(OBJ)
	make -C ../lib/my
	gcc -o $(NAME) $(OBJ) -L ../lib/my -lmy

clean:
	rm -f $(OBJ)
	make -C ../lib/my clean

fclean:	clean
	make -C ../lib/my fclean
	rm -f $(NAME)	\
	rm -f *#	\
	rm -f *~

remote:	$(OBJ)
	gcc -o $(NAME) $(OBJ) -L ../lib/my -lmy

rclean:
	rm -f $(OBJ)

rfclean: rclean
	rm -f $(NAME)	\
	rm -f *#	\
	rm -f *~

re:	fclean all

.PHONY: all remote clean rclean re fclean rfclean
