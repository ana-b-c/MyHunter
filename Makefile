##
## EPITECH PROJECT, 2024
## makefile
## File description:
## make
##
CC	=	gcc

CFLAGS	=	-Wall -Wextra -Iinclude -Llib -lcsfml-graphics\
		-lcsfml-window -lcsfml-system -lcsfml-audio -lm

SRC	=	src/main.c\
		src/game.c\
		src/events.c\
		src/lib.c\
		src/utils.c\
		src/destroy.c\
		src/update.c

OBJ	=	$(SRC:.c=.o)

NAME	=	my_hunter

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(OBJ) -o $(NAME) $(CFLAGS)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
