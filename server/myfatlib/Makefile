##
## EPITECH PROJECT, 2023
## myunilib
## File description:
## Makefile
##

SRC		=		src/add_str.c	\
				src/arr_len.c	\
				src/contain.c	\
				src/dup_arr.c	\
				src/free_arr.c	\
				src/my_get_nbr.c	\
				src/my_strdup.c	\
				src/my_strlen.c	\
				src/my_str_sepated.c	\
				src/push.c	\
				src/same_str.c	\
				src/write_char.c	\
				src/write_number.c	\
				src/write_str.c

OBJ		=		$(SRC:.c=.o)

NAME	=		libfat.a

CFLAGS	+=		-g -W -Wall -Wextra

all:	$(OBJ)
	ar rc $(NAME) $(OBJ)
clean:
	rm -f $(OBJ)
fclean: clean
	rm -f $(NAME)
re: fclean all
