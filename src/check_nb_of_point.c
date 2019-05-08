/*
** EPITECH PROJECT, 2019
** check_nb_of_pont
** File description:
** tetris
*/

#include "tetris.h"

int check_nb_point_map_game(map_game_t *map_game, int i)
{
    int count = 0;
    int a = 0;

    for (; map_game->form[a]; a++) {
        if (map_game->x + a == i)
            break;
    }
    if (!map_game->form[a])
        return (0);
    for (int n = 0; map_game->form[a][n]; n++) {
        if (map_game->form[a][n] == '*')
            count++;
    }
    return (count);
}

int check_nb_of_point(map_game_t *map_game, int i)
{
    int count = 0;

    for (; map_game; map_game = map_game->next) {
        count += check_nb_point_map_game(map_game, i);
    }
    return (count);
}