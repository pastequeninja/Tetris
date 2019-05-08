/*
** EPITECH PROJECT, 2019
** my_rog
** File description:
** init_buttons_fs_scene
*/

#include "my_rpg.h"

buttons_t *init_buttons_fs_scene(void)
{
    buttons_t *buttons = malloc(sizeof(buttons_t));
    buttons_t *(*fill_buttons[])() = {init_box_dialog, \
        init_button_status_menu, init_status_menu};

    if (!buttons)
        return (NULL);
    buttons->prev = NULL;
    for (int i = 0; i < 3; i++) {
        buttons = fill_buttons[i](buttons);
        if (!buttons)
            return (NULL);
        if (i == 2)
            break;
        if (!(buttons->next = malloc(sizeof(buttons_t))))
            return (NULL);
        buttons->next->prev = buttons;
        buttons = buttons->next;
    }
    buttons->next = NULL;
    for (; buttons->prev; buttons = buttons->prev);
    return (buttons);
}