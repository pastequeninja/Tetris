##
## EPITECH PROJECT, 2018
## makefile
## File description:
## lib
##

NAME	=	libmy.a

SRC	=	my_compute_power_rec.c		\
		my_compute_square_root.c	\
		my_getnbr.c			\
		my_isneg.c			\
		my_is_prime.c			\
		my_putchar.c			\
		my_put_nbr.c			\
		my_putstr.c			\
		my_revstr.c			\
		my_strcat.c			\
		my_strcmp.c			\
		my_strcpy.c			\
		my_str_isalpha.c		\
		my_strlen.c			\
		my_strlowcase.c			\
		my_strncat.c			\
		my_strncmp.c			\
		my_strncpy.c			\
		my_strupcase.c			\
		my_str_cat.c			\
		my_nbrlen.c			\
		my_puterror.c			\
		str_to_word_array.c		\
		my_strdup.c			\
		my_putchar_error.c		\
		my_put_nbr_error.c		\
		nbr_to_str.c			\
		free_array.c			\
		my_putarray.c			\
		my_arraydup.c			\
		my_arraylen.c			\
		my_arraycpy.c			\
		my_strdupcat.c			\
		my_swap.c			\
		my_realloc_array.c		\
		delete_line_array.c		\
		str_word_array.c

OBJS	=	$(SRC:.c=.o)

CFLAGS	=	-I./../../include -W -Wall -Wextra -Werror

COMPL	=	ar rc

CC	=	gcc

RM	=	rm -f

all: $(NAME)

$(NAME): $(OBJS)
	$(COMPL) $(NAME) $(OBJS)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

debug: CFLAGS += -g

debug: re
