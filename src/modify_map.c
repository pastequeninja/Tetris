/*
** EPITECH PROJECT, 2019
** tetris
** File description:
** change map size with flags
*/

#include "tetris.h"

char *fill_x(int *i, char *x, char *x_and_y)
{
    int j = 0;

    while (x_and_y[(*i)] != '\0') {
        if (x_and_y[(*i)] == ',')
            break;
        x[j] = x_and_y[(*i)];
        (*i)++;
        j++;
    }
    x[(*i)] = '\0';
    return x;
}

char *fill_y(int *i, char *y, char *x_and_y)
{
    int j = 0;

    (*i)++;
    while (x_and_y[(*i)] != '\0') {
        y[j] = x_and_y[(*i)];
        (*i)++;
        j++;
    }
    y[j] = '\0';
    return y;
}

bool check_data_size(char *x_and_y)
{
    int virgule = 1;
    int i = 0;

    while (x_and_y[i] != '\0') {
        if (x_and_y[i] == ',')
            virgule = 0;
        if ((x_and_y[i] < '0' || x_and_y[i] > '9') && x_and_y[i] != ',')
            return false;
        i++;
    }
    if (virgule == 1)
        return false;
    return true;
}

int change_size_map(game_mode_t *game, char *x_and_y)
{
    int i = 0;
    char *x = malloc(sizeof(char) * my_strlen(x_and_y));
    char *y = malloc(sizeof(char) * my_strlen(x_and_y));

    if (check_data_size(x_and_y) == false)
        return (84);
    if (x == NULL || y == NULL)
        return (84);
    x = fill_x(&i, x, x_and_y);
    y = fill_y(&i, y, x_and_y);
    game->size_x = my_getnbr(x);
    game->size_y = my_getnbr(y);
    if (game->size_x == 0 || game->size_y == 0)
        return (84);
    return (0);
}
