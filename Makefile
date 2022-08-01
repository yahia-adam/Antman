##
## EPITECH PROJECT, 2021                                                                                                                                                                             
## Makefile                                                                                                                                                                                          
## File description:                                                                                                                                                                                 
## It should perform the following actions                                                                                                                                                          
##                                                                                                                                                                                               

ANTMAN = antman

GIANTMAN = giantman

all:
	make -C $(ANTMAN)
	make -C $(GIANTMAN)

clean:
	rm -f $(OBJ)

fclean:	clean
	make fclean -C $(ANTMAN)
	make fclean -C $(GIANTMAN)

re:	fclean all