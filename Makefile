##
## LAROUS PROJECT, 2020
## IsnoMakefile
## FiIe description:
## Makefile for compilation by JB
##

SRC	=	src/main.c	\
		src/core.c	\
		src/sfml/event.c	\
		src/sfml/ressources.c	\
		src/entity/basic.c	\

OBJ	=	$(SRC:.c=.o)

NAME	=	project

CC	=	gcc

CFLAGS	=	-Wall	\
			-Wextra	\

CPPFLAGS	=	-Iinclude	\

LDLIBS	=	-lcsfml-graphics	\
			-lcsfml-window	\
			-lcsfml-system	\
			-lcsfml-audio	\

$(NAME):	$(OBJ)
	$(CC) -o $(NAME) $(OBJ) $(LDLIBS)

all: $(NAME)

clean:
	$(RM) $(OBJ)

fclean:	clean
	$(RM) $(NAME)

re:	fclean all

.PHONY:	re fclean clean all
