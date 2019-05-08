/*
** EPITECH PROJECT, 2019
** touch_a_form
** File description:
** tetris
*/

#include "tetris.h"

bool point_touch_smth(actual_form_t *actual_form, map_game_t *map_game, \
int i, int a)
{
    int form_x = actual_form->x + i;
    int form_y = actual_form->y + a;
    int map_x = map_game->x;
    int map_y = map_game->y;
    int x = 0;

    for (; map_game->form[map_x - map_game->x]; map_x++) {
        x = map_x - map_game->x;
        if (map_x != form_x)
            continue;
        for (map_y = map_game->y; map_game->form[x][map_y - map_game->y] && \
        map_y != form_y; map_y++);
        if (map_y == form_y && map_game->form[x][map_y - map_game->y] == '*')
            return (true);
    }
    return (false);
}

bool check_points_in_line(map_game_t *map_game, actual_form_t *actual_form, \
int i)
{
    for (int a = 0; actual_form->figure[i][a]; a++) {
        if (actual_form->figure[i][a] == ' ')
            continue;
        if (point_touch_smth(actual_form, map_game, i, a) == true)
            return (true);
    }
    return (false);
}

bool touch_an_other_form(map_game_t *map_game, actual_form_t *actual_form)
{
    for (int i = 0; actual_form->figure[i]; i++) {
        if (check_points_in_line(map_game, actual_form, i) == true)
            return (true);
    }
    return (false);
}

bool touch_a_form(actual_form_t *actual_form, map_game_t *map_game, \
game_mode_t game_mode)
{
    for (; map_game; map_game = map_game->next) {
        if (touch_an_other_form(map_game, actual_form) == true) {
            return (true);
        }
    }
    if (touch_side(actual_form, game_mode) == true)
        return (true);
    return (false);
}