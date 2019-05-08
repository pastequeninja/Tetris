/*
** EPITECH PROJECT, 2019
** tetris
** File description:
** display_the game
*/

#include "tetris.h"

void display_the_game(display_t *display, game_mode_t game)
{
    attron(COLOR_PAIR(1));
    display_smth(display->letter_t, 4, 2);
    attron(COLOR_PAIR(2));
    display_smth(display->letter_e, 4, 12);
    attron(COLOR_PAIR(3));
    display_smth(display->letter_t, 4, 20);
    attron(COLOR_PAIR(4));
    display_smth(display->letter_r, 4, 30);
    attron(COLOR_PAIR(5));
    display_smth(display->letter_i, 5, 40);
    attron(COLOR_PAIR(6));
    display_smth(display->letter_s, 4, 44);
    attron(COLOR_PAIR(7));
    display_smth(display->board_display, 0, 60);
    display_smth(display->map, 20, 10);
    if (game.display_next == true)
        display_smth(display->next, 20, game.size_y + 15);
}
