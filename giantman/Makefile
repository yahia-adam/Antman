##
## EPITECH PROJECT, 2022
## makfile
## File description:
## makefile
##

SRC		=	../src/main_giantman.c			\
			../src/giantman.c	\
			../src/my_put.c			\
			../src/read_file.c		\
			../src/my_intostr.c		\
			../src/my_getnbr.c		\

OBJ		=	$(SRC:.c=.o)

NAME	= 	giantman

DEBUG	= -g3

CPPFLAGS = -I../include/

all:	$(OBJ)
		gcc -o $(NAME) $(OBJ) $(CPPFLAGS) -Wall -Werror
debug:
		gcc -o $(NAME) $(OBJ) $(CPPFLAGS) $(DEBUG)
clean:
	rm -f $(OBJ)
	rm -f *~
	rm -f *.o

fclean:	clean
		rm -f $(NAME)

re:	fclean all
