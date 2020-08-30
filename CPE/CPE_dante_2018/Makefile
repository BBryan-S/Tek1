##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## Makefile
##

NAME	=	dante

all:	$(NAME)

$(NAME):
	make -C lib/my
	make -C generator remote
	make -C solver remote

clean:
	make -C lib/my clean
	make -C generator rclean
	make -C solver rclean

fclean:	clean
	make -C lib/my fclean
	make -C generator rfclean
	make -C solver rfclean

re:	fclean all

.PHONY: all clean re fclean
