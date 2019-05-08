/*
** EPITECH PROJECT, 2019
** game_mode
** File description:
** tetris
*/

#ifndef GAME_MODE_H
#define GAME_MODE_H

#include "tetris.h"

typedef struct game_mode_s {
    bool display_debug;
    char *k_left;
    char *k_right;
    char *k_turn;
    char *k_drop;
    char *k_quit;
    char *k_pause;
    bool display_next;
    int level;
    int stock_level;
    int size_x;
    int size_y;
    int speed;
    int sleep;
    int stock_sleep;
    int next_level;
    int score;
    int high_score;
    int nb_line;
} game_mode_t;

#endif
