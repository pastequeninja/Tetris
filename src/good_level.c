/*
** EPITECH PROJECT, 2019
** is_an_int
** File description:
** tetris
*/

#include "tetris.h"

bool good_level(char *str)
{
    if (my_strlen(str) == 0)
        return (false);
    if (str[0] == '0' && str[1] != '\0')
        return (false);
    for (int i = 0; str[i]; i++) {
        if (str[i] < '0' || str[i] > '9')
            return (false);
    }
    return (true);
}