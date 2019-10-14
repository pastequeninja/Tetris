##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## my_rpg
##

NAME	=	tetris

SRCS	=	src/main.c			\
		src/fill_struct.c		\
		src/init_data_form.c		\
		src/begin_game.c		\
		src/text_file_in_tab.c		\
		src/init_display.c		\
		src/display_the_game.c		\
		src/play_game.c			\
		src/display_smth.c		\
		src/form_falls.c		\
		src/touch_a_form.c		\
		src/analyse_events.c		\
		src/put_form_in_map_game.c	\
		src/touch_side.c		\
		src/turn_form.c			\
		src/map_parsing.c		\
		src/init_map.c			\
		src/delete_line_map_game.c	\
		src/check_nb_of_point.c		\
		src/line_complete.c		\
		src/refresh.c			\
		src/display_in_board.c		\
		src/check_line_complete.c	\
		src/change_actual_and_next.c	\
		src/init_high_score.c		\
		src/condition_lose.c		\
		src/delete_too_much_line.c	\
		src/flags.c			\
		src/print_help_and_tetriminos.c	\
		src/modify_map.c		\
		src/init_termcaps.c		\
		src/init_level.c		\
		src/init_next.c			\
		src/bad_dimension.c		\
		src/calculate_size_display.c	\
		src/compare.c			\
		src/sort_list.c			\
		src/term_mode.c			\
		src/init_game.c			\
		src/switch_flags.c		\
		src/good_level.c		\
		src/check_real_form_size.c	\
		src/configure_figure.c

OBJS	=	$(SRCS:.c=.o)

LIB	=	-L lib/my

MY	=	-lmy

NCURSES	=	-lncurses

CC	=	cl.exe

LINK = link.exe

RM	=	rm -f

CFLAGS	=	-I include -W -Wall -Wextra

all: $(NAME)

$(NAME): $(OBJS)
	$(LINK) -C lib/my
	$(CC) -o $(NAME) $(OBJS) $(LIB) $(MY) $(NCURSES)

clean:
	$(LINK) clean -C lib/my
	$(RM) $(OBJS)

fclean: clean
	$(LINK) fclean -C lib/my
	$(RM) $(NAME)

debug: CFLAGS += -g
debug: re
re: fclean all
