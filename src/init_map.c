/*
** EPITECH PROJECT, 2019
** inti_map
** File description:
** tetris
*/

#include "tetris.h"

char **malloc_map(char **map, int x, int y)
{
    for (int i = 0; i < x + 2; i++) {
        map[i] = malloc(sizeof(char) * (y + 3));
        if (!map[i])
            return (NULL);
    }
    map[x + 2] = NULL;
    return (map);
}

char *init_special_line(char *str, int y, char side, char basic)
{
    str[0] = side;
    for (int i = 1; i < y + 1; i++)
        str[i] = basic;
    str[y + 1] = side;
    str[y + 2] = '\0';
    return (str);
}

char **init_map(game_mode_t game_mode)
{
    int x = game_mode.size_x;
    int y = game_mode.size_y;
    char **map = malloc(sizeof(char *) * (x + 3));

    if (!map)
        return (NULL);
    map = malloc_map(map, x, y);
    if (!map)
        return (NULL);
    map[0] = init_special_line(map[0], y, '+', '-');
    for (int i = 1; i < x + 1; i++)
        map[i] = init_special_line(map[i], y, '|', ' ');
    map[x + 1] = init_special_line(map[x + 1], y, '+', '-');
    return (map);
}