/*
** EPITECH PROJECT, 2019
** tetris
** File description:
** analyse_events
*/

#include "tetris.h"

int other_events(map_game_t *map_game, actual_form_t *actual_form, \
game_mode_t *game_mode, char *str)
{
    if (!my_strcmp(str, game_mode->k_right) && game_mode->speed != DONT_MOVE) {
        actual_form->y++;
        if (touch_a_form(actual_form, map_game, (*game_mode)) == true)
            actual_form->y--;
        return (CONTINUE);
    }
    if (!my_strcmp(str, game_mode->k_left) && game_mode->speed != DONT_MOVE) {
        actual_form->y--;
        if (touch_a_form(actual_form, map_game, (*game_mode)) == true)
            actual_form->y++;
        return (CONTINUE);
    }
    if (!my_strcmp(str, game_mode->k_turn) && game_mode->speed != DONT_MOVE) {
        actual_form = turn_form(actual_form, map_game, (*game_mode));
        if (!actual_form)
            return (END);
        return (CONTINUE);
    }
    return (CONTINUE);
}

int analyse_events(map_game_t *map_game, actual_form_t *actual_form, \
game_mode_t *game_mode)
{
    int verif;
    char buffer[256];

    term_mode(GAME);
    verif = read(0, buffer, 256);
    buffer[verif] = '\0';
    term_mode(NORMAL);
    if (!my_strcmp(buffer, game_mode->k_quit) || verif == -1)
        return (END);
    if (!my_strcmp(buffer, game_mode->k_pause)) {
        game_mode->speed = (game_mode->speed == DONT_MOVE ? 0 : DONT_MOVE);
        return (CONTINUE);
    }
    if (!my_strcmp(buffer, game_mode->k_drop)) {
        game_mode->sleep = (game_mode->sleep == 1000 ? \
game_mode->stock_sleep : 1000);
        return (CONTINUE);
    }
    return (other_events(map_game, actual_form, game_mode, buffer));
}
