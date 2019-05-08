/*
** EPITECH PROJECT, 2019
** tetris
** File description:
** init
*/

#include "tetris.h"

int init_default_key(game_mode_t *game_mode)
{
    game_mode->k_left = tigetstr("kcub1");
    game_mode->k_right = tigetstr("kcuf1");
    game_mode->k_turn = tigetstr("kcuu1");
    game_mode->k_drop = tigetstr("kcud1");
    game_mode->k_quit = my_strdup("q");
    game_mode->k_pause = my_strdup(" ");
    if (!game_mode->k_left || !game_mode->k_right || !game_mode->k_turn \
        || !game_mode->k_drop || !game_mode->k_quit || !game_mode->k_pause)
        return (FAILURE);
    return (SUCCESS);
}

int init_game_mode(game_mode_t *game_mode)
{
    if (init_default_key(game_mode) == FAILURE)
        return (FAILURE);
    game_mode->display_next = true;
    game_mode->level = 1;
    game_mode->stock_level = 1;
    game_mode->size_x = 20;
    game_mode->size_y = 10;
    game_mode->speed = 0;
    game_mode->sleep = 8000;
    game_mode->stock_sleep = 8000;
    game_mode->next_level = 0;
    game_mode->nb_line = 0;
    game_mode->score = 0;
    game_mode->high_score = init_high_score();
    game_mode->display_debug = false;
    return (SUCCESS);
}
