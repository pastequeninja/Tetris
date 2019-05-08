/*
** EPITECH PROJECT, 2019
** refrsh
** File description:
** tetris
*/

#include "tetris.h"

void refresh_the_next(display_t *display, game_mode_t game)
{
    int x = 1;
    int y = 0;

    for (int i = 21; display->next[x + 1]; i++, x++) {
        y = 1;
        for (int a = game.size_y + 16; display->next[x][y + 1]; a++, y++)
            mvprintw(i, a, " ");
    }
}

void refresh_the_map(game_mode_t *game_mode)
{
    for (int i = 21; i < game_mode->size_x + 21; i++) {
        for (int a = 11; a < game_mode->size_y + 11; a++)
            mvprintw(i, a, " ");
    }
}

void refesh_the_board(void)
{
    for (int i = 3; i <= 12; i++) {
        for (int a = 73; a <= 97; a++)
            mvprintw(i, a, " ");
    }
}