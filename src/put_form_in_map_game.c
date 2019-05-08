/*
** EPITECH PROJECT, 2019
** put_for_in_map_game
** File description:
** tetris
*/

#include "tetris.h"

map_game_t *fill_map_game(map_game_t *map_game, \
actual_form_t *actual_form)
{
    map_game->form = my_arraydup(actual_form->figure);
    if (!map_game->form)
        return (NULL);
    map_game->x = actual_form->x;
    map_game->y = actual_form->y;
    map_game->color = actual_form->form->color;
    return (map_game);
}

map_game_t *put_form_in_map_game(map_game_t *map_game, \
actual_form_t *actual_form)
{
    if (!map_game) {
        map_game = malloc(sizeof(map_game_t));
        if (!map_game)
            return (NULL);
        map_game->prev = NULL;
        map_game->next = NULL;
        return (fill_map_game(map_game, actual_form));
    }
    for (; map_game->next; map_game = map_game->next);
    map_game->next = malloc(sizeof(map_game_t));
    if (!map_game->next)
        return (NULL);
    map_game->next->prev = map_game;
    map_game = map_game->next;
    map_game->next = NULL;
    map_game = fill_map_game(map_game, actual_form);
    if (!map_game)
        return (NULL);
    for (; map_game->prev; map_game = map_game->prev);
    return (map_game);
}