##
## LAROUS PROJECT, 2020
## IsnoMakefile
## FiIe description:
## Makefile for compilation by JB
##

SRC	=	src/main.c	\
		src/core.c	\
		src/entity/basic.c	\
		src/sfml/ressources.c	\
		src/sfml/event.c	\

OBJ	=	$(SRC:.c=.o)

NAME	=	project

CC	=	gcc

RM	=	rm -f

CFLAGS	=	-Wall	\
			-Wextra	\
			-Iinclude	\

SFMLFLAGS =	-lcsfml-graphics	\
			-lcsfml-window	\
			-lcsfml-system	\
			-lcsfml-audio	\

$(NAME):	$(OBJ)
	$(CC) -o $(NAME) $(OBJ) $(CFLAGS) $(SFMLFLAGS)

all: $(NAME)

clean:
	$(RM) $(OBJ)

fclean:	clean
	$(RM) $(NAME)

re:	fclean all

.PHONY:	re fclean clean all
