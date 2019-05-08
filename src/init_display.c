/*
** EPITECH PROJECT, 2019
** init_display
** File description:
** tetris
*/

#include "tetris.h"

display_t *init_display(game_mode_t game_mode, form_t *form)
{
    display_t *display = malloc(sizeof(display_t));

    if (!display)
        return (NULL);
    if (!(display->board_display = text_file_in_tab("map/board_display")))
        return (NULL);
    if (!(display->map = init_map(game_mode)))
        return (NULL);
    if (!(display->next = init_next(form)))
        return (NULL);
    if (!(display->letter_t = text_file_in_tab("map/letter_t")))
        return (NULL);
    if (!(display->letter_e = text_file_in_tab("map/letter_e")))
        return (NULL);
    if (!(display->letter_r = text_file_in_tab("map/letter_r")))
        return (NULL);
    if (!(display->letter_i = text_file_in_tab("map/letter_i")))
        return (NULL);
    if (!(display->letter_s = text_file_in_tab("map/letter_s")))
        return (NULL);
    return (display);
}