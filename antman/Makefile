##
## EPITECH PROJECT, 2021                                                                                                                                                                             
## Makefile                                                                                                                                                                                          
## File description:                                                                                                                                                                                 
## It should perform the following actions                                                                                                                                                          
##                                                                                                                                                                                                   

SRC		=	../src/main_antman.c	\
			../src/my_put.c			\
			../src/antman_img.c	\
			../src/antman_lyrics.c	\
			../src/read_file.c		\
			../src/my_intostr.c		\
			../src/my_getnbr.c		\

OBJ		=	$(SRC:.c=.o)

CC 		=	gcc

NAME	= 	antman

DEBUG	= -g

CPPFLAGS = -I../include/

all:	$(OBJ)
		$(CC) -o $(NAME) $(OBJ) $(CPPFLAGS) -Wall -Werror
debug:
		gcc -o $(NAME) $(OBJ) $(CPPFLAGS) -g
clean:
	rm -f $(OBJ)
	rm -f *~
	rm -f *.o

fclean:	clean
		rm -f $(NAME)

re:	fclean all
