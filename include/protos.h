/*
** EPITECH PROJECT, 2019
** proto
** File description:
** bootstrap
*/

#ifndef PROTOS_H_
#define PROTOS_H_

#include "tetris.h"

char *new_name(char *file_name);
form_t *configure_figure(form_t *form, char *complete_name);
int switch_flags(int opt, game_mode_t *game);
char *fill_tmp(int j, int i, char **form);
form_t *configure_figure(form_t *form, char *complete_name);
int init_game_mode(game_mode_t *game_mode);
int init_default_key(game_mode_t *game_mode);
void putstr_key(char *);
char *change_key(char *opt_arg, char *);
int change_size_map(game_mode_t *game, char *x_and_y);
void print_help(char **av);
void print_debug_mode(form_t *form, game_mode_t);
int check_arguments(int ac, char **av, game_mode_t *);
bool colomun_is_empty(char **str, int count, int j);
int parse_map(char *, char **);
int stats(int);
char **str_parse_double(char *);
char**str_parse_double(char *);
form_t *fill_struct(void);
form_t *fill_data(char *file_name, form_t *form);
int begin_game(form_t *, game_mode_t);
display_t *init_display(game_mode_t, form_t *form);
char **text_file_in_tab(char *);
void display_the_game(display_t *, game_mode_t);
int play_game(form_t *, int, game_mode_t, display_t *);
void display_smth(char **, int, int);
int form_falls(actual_form_t *, map_game_t *, game_mode_t *);
bool touch_a_form(actual_form_t *, map_game_t *, game_mode_t);
form_t *what_form(form_t *, int);
map_game_t *put_form_in_map_game(map_game_t *, actual_form_t *);
int analyse_events(map_game_t *, actual_form_t *, game_mode_t *);
bool touch_side(actual_form_t *, game_mode_t);
actual_form_t *turn_form(actual_form_t *, map_game_t *, game_mode_t);
char **init_map(game_mode_t);
int check_nb_of_point(map_game_t *, int);
int delete_line_map_game(map_game_t *, int);
int line_complete(map_game_t *, game_mode_t *);
void refresh_the_map(game_mode_t *);
void refresh_the_next(display_t *, game_mode_t);
void refesh_the_board(void);
void display_in_board(game_mode_t);
int check_line_complete(map_game_t *, game_mode_t *);
int change_actual_and_next(actual_form_t *, form_t *, game_mode_t);
int init_high_score(void);
map_game_t *condition_lose(actual_form_t * , map_game_t *, game_mode_t *);
char **delete_too_much_line(char **);
int init_termcaps(char **);
int term_mode(int);
void init_level_begin(game_mode_t *);
char **malloc_map(char **map, int x, int y);
char **init_next(form_t *);
void display_map_game(map_game_t *);
void bad_dimension(game_mode_t, display_t *, map_game_t *);
void calculate_size_display(display_t *);
int compare_two_str(char *, char *);
void sort_list(form_t *);
bool good_level(char *str);
int check_real_form_size(int, int, char **);

#endif
