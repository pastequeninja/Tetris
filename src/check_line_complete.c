/*
** EPITECH PROJECT, 2019
** check_line_complete
** File description:
** tetris
*/

#include "tetris.h"

int check_line_complete(map_game_t *map_game, game_mode_t *game_mode)
{
    if (line_complete(map_game, game_mode) == FAILURE)
        return (FAILURE);
    game_mode->sleep = game_mode->stock_sleep;
    return (SUCCESS);
}