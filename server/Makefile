##
## EPITECH PROJECT, 2022
## Makefile
## File description:
## do something apparently
##

SRC		=	./src/main.c	\
			./src/check_print_help.c	\
			./src/open_server.c		\
			./src/constructor_destructor.c	\
			./src/main_node.c		\
			./src/handle_fds.c	\
			./src/read_user.c	\
			./src/client.c	\
			./src/command_list.c	\
			./src/write_user.c	\
			./src/is_not_logged.c	\
			./src/commands/user.c	\
			./src/commands/pass.c	\
			./src/commands/quit.c	\
			./src/commands/noop.c	\
			./src/commands/help.c	\
			./src/commands/pwd.c	\
			./src/commands/cwd.c	\
			./src/commands/cdup.c	\
			./src/commands/dele.c


OBJ		=	$(SRC:.c=.o)

NAME	=	myftp

CFLAGS +=	-g -W -Wall -Wextra

LIB		=	-L./myfatlib -lfat


all:	$(OBJ)
	make -C ./myfatlib
	gcc -o $(NAME) $(OBJ) $(CFLAGS) $(LIB)

clean:
	rm -f $(OBJ)
	make -C ./myfatlib clean

fclean: 	clean
	rm -f $(NAME)
	make -C ./myfatlib fclean

re:	fclean all
