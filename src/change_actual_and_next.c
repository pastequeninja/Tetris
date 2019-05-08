/*
** EPITECH PROJECT, 2019
** change_actual_and_next
** File description:
** tetris
*/

#include "tetris.h"

int change_actual_and_next(actual_form_t *actual_form, form_t *next_form, \
game_mode_t game_mode)
{
    actual_form->form = next_form;
    actual_form->figure = my_arraydup(actual_form->form->figure);
    if (!actual_form->figure)
        return (FAILURE);
    actual_form->x = BEGIN_LINE;
    actual_form->y = (game_mode.size_y - actual_form->form->x) / 2 + \
    BEGIN_COLUMN;
    return (SUCCESS);
}