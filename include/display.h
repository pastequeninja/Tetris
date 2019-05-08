/*
** EPITECH PROJECT, 2019
** tetris
** File description:
** display
*/

#ifndef DISPLAY_H
#define DISPLAY_H

#include "tetris.h"

typedef struct display_s {
    char **letter_t;
    char **letter_e;
    char **letter_r;
    char **letter_i;
    char **letter_s;
    char **board_display;
    char **logo;
    char **map;
    char **next;
    int size_x_map;
    int size_y_map;
} display_t;

#endif
