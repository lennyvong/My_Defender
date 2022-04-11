##
## EPITECH PROJECT, 2021
## makefile
## File description:
## Compil programme for project my_printf
##

SRC	=	my_strlen.c	\
		my_strcat.c	\
		move_rect.c	\
		add_tab_int.c	\
		set_texture.c	\
		array/my_str_to_word_array.c	\
		array/put_str_to_word_array.c	\
		array/my_array_len.c	\
		array/my_arraycpy.c	\
		array/my_free_array.c	\
		tools/tools.c	\
		my_itoa.c	\
		my_getnbr.c	\

OBJ	=	$(SRC:.c=.o)

NAME	=	libmy.a

CPPFLAGS = -Wall -Wextra

CPPFLAGS = -I../includes

all:	$(NAME)

$(NAME):	$(OBJ)
	ar rc $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re : fclean all

.PHONY:	all clean fclean re
