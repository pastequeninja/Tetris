/*
** EPITECH PROJECT, 2019
** condition_lse
** File description:
** tetris
*/

#include "tetris.h"

void free_map_game(map_game_t *map_game)
{
    map_game_t *tmp;

    for (; map_game->prev; map_game = map_game->prev);
    while (map_game) {
        free_array(map_game->form);
        tmp = map_game;
        map_game = map_game->next;
        free(tmp);
    }
}

void re_init_game_mode(game_mode_t *game_mode)
{
    if (game_mode->score > game_mode->high_score)
        game_mode->high_score = game_mode->score;
    game_mode->score = 0;
    game_mode->level = game_mode->stock_level;
    game_mode->speed = 0;
    game_mode->sleep = game_mode->stock_sleep;
    game_mode->next_level = 0;
    game_mode->nb_line = 0;
}

map_game_t *condition_lose(actual_form_t *actual_form, map_game_t *map_game, \
game_mode_t *game_mode)
{
    while (getch() != ERR);
    if (touch_a_form(actual_form, map_game, (*game_mode)) == false)
        return (map_game);
    attron(COLOR_PAIR(7));
    mvprintw(16, 3, "Press any key to restart the game");
    while (getch() == ERR) {
        refesh_the_board();
        display_in_board((*game_mode));
    }
    mvprintw(16, 3, "                                 ");
    free_map_game(map_game);
    re_init_game_mode(game_mode);
    return (NULL);
}