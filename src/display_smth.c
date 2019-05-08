/*
** EPITECH PROJECT, 2019
** tetris
** File description:
** display_smth
*/

#include "tetris.h"

void not_display_the_space(char *str, int x, int y)
{
    for (int i = 0; str[i]; i++, y++) {
        if (str[i] == ' ')
            continue;
        mvprintw(x, y, "%c", str[i]);
    }
}

void display_smth(char **arr, int x, int y)
{
    for (int i = 0; arr[i]; i++, x++)
        not_display_the_space(arr[i], x, y);
}