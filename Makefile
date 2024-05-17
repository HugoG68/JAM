##
## EPITECH PROJECT, 2023
## Projet Jam
## File description:
## Makefile
##

SRC		=		src/main.cpp	\
				src/Game/Game.cpp	\
				src/Player/Player.cpp	\
				src/Menu/Menu.cpp	\
				src/Menu/Button.cpp	\
				src/Factory/Factory.cpp \
				src/Text/Text.cpp

OBJ		=		$(SRC:.cpp=.o)

NAME	=		Jetpack

CXXFLAGS	+=		-g -I./src -std=c++20 -Wall -Wextra -Werror -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio -lm

all:	$(OBJ)
	g++ -o $(NAME) $(OBJ) $(CXXFLAGS)
clean:
	rm -f $(OBJ)
fclean: clean
	rm -f $(NAME)
re: fclean all