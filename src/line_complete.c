/*
** EPITECH PROJECT, 2019
** line_complete
** File description:
** tetris
*/

#include "tetris.h"

void increase_level(game_mode_t *game_mode)
{
    if (game_mode->next_level == 10) {
        game_mode->level++;
        game_mode->next_level = 0;
        game_mode->stock_sleep -= 200;
    }
}

int line_complete(map_game_t *map_game, game_mode_t *game_mode)
{
    int max = game_mode->size_y;
    int verif = 0;
    int count = 12;

    for (int i = BEGIN_LINE; i < game_mode->size_x + BEGIN_LINE; i++) {
        count = check_nb_of_point(map_game, i);
        if (count == max) {
            game_mode->next_level++;
            increase_level(game_mode);
            game_mode->score += 15;
            game_mode->nb_line++;
            verif = delete_line_map_game(map_game, i);
        }
        if (verif == FAILURE)
            return (FAILURE);
    }
    return (SUCCESS);
}