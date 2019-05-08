/*
** EPITECH PROJECT, 2019
** dlete_line_map_game
** File description:
** tetris
*/

#include "tetris.h"

void move_line_above(map_game_t *map_game, int i)
{
    for (; map_game->prev; map_game = map_game->prev);
    for (; map_game; map_game = map_game->next) {
        if (map_game->x <= i)
            map_game->x++;
    }
}

map_game_t *delete_a_line_if_we_must(map_game_t *map_game, int i)
{
    int a = 0;

    for (; map_game->form[a]; a++) {
        if (map_game->x + a == i)
            break;
    }
    if (!map_game->form[a])
        return (map_game);
    map_game->form = delete_line_array(map_game->form, a);
    if (!map_game->form)
        return (NULL);
    return (map_game);
}

int delete_line_map_game(map_game_t *map_game, int i)
{
    for (; map_game; map_game = map_game->next) {
        map_game = delete_a_line_if_we_must(map_game, i);
        if (!map_game)
            return (FAILURE);
        if (map_game->x <= i)
            map_game->x++;
    }
    return (SUCCESS);
}
