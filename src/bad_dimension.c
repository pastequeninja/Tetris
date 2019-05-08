/*
** EPITECH PROJECT, 2019
** bad_dimension
** File description:
** tetris
*/

#include "tetris.h"

void bad_dimension(game_mode_t game_mode, display_t *display, \
map_game_t *map_game)
{
    int tmp_lines = LINES;
    int tmp_cols = COLS;

    clear();
    while (display->size_x_map > LINES || display->size_y_map > COLS) {
        mvprintw(tmp_lines / 2, tmp_cols / 2 - 10, "                     ");
        mvprintw(LINES / 2, COLS / 2 - 10, "enlarge your terminal");
        tmp_lines = LINES;
        tmp_cols = COLS;
        refresh();
    }
    clear();
    display_the_game(display, game_mode);
    display_map_game(map_game);
}