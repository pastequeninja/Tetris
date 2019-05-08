/*
** EPITECH PROJECT, 2019
** form_falls
** File description:
** tetris
*/

#include "tetris.h"

void display_map_game(map_game_t *map_game)
{
    for (; map_game; map_game = map_game->next) {
        attron(COLOR_PAIR(map_game->color));
        display_smth(map_game->form, map_game->x, map_game->y);
    }
}

int form_falls(actual_form_t *actual_form, \
map_game_t *map_game, game_mode_t *game_mode)
{
    refresh_the_map(game_mode);
    display_map_game(map_game);
    attron(COLOR_PAIR(actual_form->form->color));
    display_smth(actual_form->figure, actual_form->x, actual_form->y);
    if (game_mode->speed == DONT_MOVE)
        return (NO_TOUCH);
    game_mode->speed++;
    if (game_mode->speed % game_mode->sleep != 0)
        return (NO_TOUCH);
    game_mode->speed = 0;
    actual_form->x++;
    if (touch_a_form(actual_form, map_game, (*game_mode)) == false)
        return (NO_TOUCH);
    actual_form->x--;
    return (TOUCH);
}
