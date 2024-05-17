##
## EPITECH PROJECT, 2023
## Projet Jam
## File description:
## Makefile
##

SRC		=		src/main.cpp	\
				src/Game/Game.cpp	\
				src/Player/Player.cpp	\

OBJ		=		$(SRC:.cpp=.o)

NAME	=		Jetpack

CFLAGS	+=		-g  -std=c++20 -Wall -Wextra -Werror -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio -lm

all:	$(OBJ)
	g++ -o $(NAME) $(OBJ) $(CFLAGS)
clean:
	rm -f $(OBJ)
fclean: clean
	rm -f $(NAME)
re: fclean all