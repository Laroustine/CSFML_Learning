##
## EPITECH PROJECT, 2020
## IsnoMakefile
## File description:
## Makefile for compilation by JB
##

SRC	=	src/main.c	\
		src/core.c	\
		src/entity/basic.c	\

OBJ	=	$(SRC:.c=.o)

NAME	=	project

CC	=	gcc

RM	=	rm -f

CFLAGS	=	-std=gnu11	\
			-Wall	\
			-Wextra	\
			-g	\
			-Iinclude	\

SFMLFLAGS =	-lsfml-graphics	\
			-lsfml-window	\
			-lsfml-audio	\
			-lsfml-system	\

$(NAME):	$(OBJ)
	$(CC) -o $(NAME) $(OBJ) $(CFLAGS) $(SFMLFLAGS)

all: $(NAME)

clean:
	$(RM) $(OBJ)

fclean:	clean
	$(RM) $(NAME)

re:	fclean all

.PHONY:	re fclean clean all
