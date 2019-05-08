/*
** EPITECH PROJECT, 2019
** display_
** File description:
** tetris
*/

#include "tetris.h"

void display_in_board(game_mode_t game_mode)
{
    clock_t i = clock() / CLOCKS_PER_SEC;
    int min = i / 60;

    i -= (min * 60);
    attron(COLOR_PAIR(7));
    mvprintw(3, 97 - my_nbrlen(game_mode.high_score), "%d", \
    game_mode.high_score);
    mvprintw(5, 97 - my_nbrlen(game_mode.score), "%d", game_mode.score);
    mvprintw(7, 97 - my_nbrlen(game_mode.nb_line), "%d", game_mode.nb_line);
    mvprintw(9, 97 - my_nbrlen(game_mode.level), "%d", game_mode.level);
    if (i < 10) {
        mvprintw(11, 97 - my_nbrlen(i) - 1, "0%d", i);
        i = (i == 0 ? 10 : i * 10);
    } else
        mvprintw(11, 97 - my_nbrlen(i), "%d", i);
    if (min < 10)
        mvprintw(11, 97 - my_nbrlen(min) - 2 - my_nbrlen(i), "0%d:", min);
    else
        mvprintw(11, 97 - my_nbrlen(min) - 1 - my_nbrlen(i), "%d:", min);
}