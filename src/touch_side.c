/*
** EPITECH PROJECT, 2019
** tetris
** File description:
** touch_side
*/

#include "tetris.h"

bool check_line(actual_form_t *actual_form, int i, game_mode_t game_mode)
{
    int form_x;
    int form_y;

    for (int a = 0; actual_form->figure[i][a]; a++) {
        if (actual_form->figure[i][a] == ' ')
            continue;
        form_x = actual_form->x + i;
        form_y = actual_form->y + a;
        if (form_y == 10 || form_y == game_mode.size_y + BEGIN_COLUMN || \
            form_x == game_mode.size_x + BEGIN_LINE)
            return (true);
    }
    return (false);
}

bool touch_side(actual_form_t *actual_form, game_mode_t game_mode)
{
    for (int i = 0; actual_form->figure[i]; i++) {
        if (check_line(actual_form, i, game_mode) == true)
            return (true);
    }
    return (false);
}