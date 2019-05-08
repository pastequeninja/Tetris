/*
** EPITECH PROJECT, 2019
** inti_level
** File description:
** tetris
*/

#include "tetris.h"

void init_level_begin(game_mode_t *game_mode)
{
    game_mode->stock_level = game_mode->level;

    for (int i = 1; i != game_mode->level; i++) {
        if (game_mode->sleep != 2000) {
            game_mode->sleep -= 200;
            game_mode->stock_sleep -= 200;
        }
    }
}