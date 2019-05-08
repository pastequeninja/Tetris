/*
** EPITECH PROJECT, 2019
** init_next_
** File description:
** tetris
*/

#include "tetris.h"

char *init_line_next(char *str, int y, char *buff)
{
    str[0] = buff[0];
    for (int i = 1; i < y + 1; i++)
        str[i] = buff[1];
    str[y + 1] = buff[2];
    str[y + 2] = '\0';
    return (str);
}

int init_x_next(form_t *form)
{
    int x = form->x;

    for (; form; form = form->next) {
        if (form->x > x)
            x = form->x;
    }
    return (x + 4);
}

int init_y_next(form_t *form)
{
    int y = form->y;

    for (; form; form = form->next) {
        if (form->y > y)
            y = form->y;
    }
    return (y + 8);
}

char **init_next(form_t *form)
{
    int x = init_x_next(form);
    int y = init_y_next(form);
    char fs_buff[] = "N-E";
    char sc_buff[] = "| |";
    char td_buff[] = "T-X";

    char **next = malloc(sizeof(char *) * (x + 3));

    if (!next)
        return (NULL);
    next = malloc_map(next, x, y);
    if (!next)
        return (NULL);
    next[0] = init_line_next(next[0], y, fs_buff);
    for (int i = 1; i < x + 1; i++)
        next[i] = init_line_next(next[i], y, sc_buff);
    next[x + 1] = init_line_next(next[x + 1], y, td_buff);
    return (next);
}