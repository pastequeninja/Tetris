/*
** EPITECH PROJECT, 2019
** TETRIS
** File description:
** map parsing
*/

#include "tetris.h"

int check_stars(char *str, int i)
{
    while (str[i] != '\0') {
        if (str[i] != '*' && str[i] != ' ' && str[i] != '\n')
            return 84;
        i++;
    }
    return 0;
}

int parse_first_line(char *str, int *i)
{
    int count_space = 0;
    int j = 0;

    while (str[(*i)] != '\0' && str[(*i)] != '\n') {
        if (str[(*i)] == ' ')
            count_space++;
        if ((str[(*i)] < '0' || str[(*i)] > '9') && str[(*i)] != ' ')
            return 84;
        (*i)++;
    }
    if (str[(*i)] == '\0')
        return 84;
    if (count_space != 2)
        return 84;
    j = (*i) - 1;
    if (str[j] < '0' || str[j] > '7')
        return 84;
    while (str[(*i)] != '\0' && str[(*i)] == '\n')
        (*i)++;
    return 0;
}

int parse_map(char *str, char **form)
{
    int i = 0;
    int j = 0;

    if (parse_first_line(str, &i) == 84)
        return 84;
    if (((*form) = malloc(sizeof(char) * my_strlen(str))) == NULL)
        return 84;
    if (check_stars(str, i) == 84)
        return 84;
    while (str[i] != '\0') {
        (*form)[j] = str[i];
        i++;
        j++;
    }
    (*form)[j] = '\0';
    return 0;
}
