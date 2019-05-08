/*
** EPITECH PROJECT, 2019
** map_game
** File description:
** tetris
*/

#ifndef MAP_GAME_H
#define MAP_GAME_H

#include "tetris.h"

typedef struct map_game_s {
    char **form;
    int x;
    int y;
    int color;
    struct map_game_s *next;
    struct map_game_s *prev;
} map_game_t;

#endif
