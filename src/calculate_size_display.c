/*
** EPITECH PROJECT, 2019
** calculate_size_display
** File description:
** tetris
*/

#include "tetris.h"

int init_nb_cols_display(display_t *display)
{
    int cols_fix = 100;
    int cols_move = 10 + my_strlen(display->map[0]) + 5 + \
    my_strlen(display->next[0]);

    return ((cols_fix > cols_move) ? cols_fix : cols_move);
}

int init_nb_lines_display(display_t *display)
{
    int line_map = my_arraylen(display->map) + 20;
    int line_next = my_arraylen(display->next) + 20;

    return ((line_map > line_next) ? line_map : line_next);
}

void calculate_size_display(display_t *display)
{
    int nb_lines = init_nb_lines_display(display);
    int nb_cols = init_nb_cols_display(display);

    display->size_x_map = nb_lines;
    display->size_y_map = nb_cols;
}