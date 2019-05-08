/*
** EPITECH PROJECT, 2019
** delete_toomush_line
** File description:
** tetris
*/

#include "tetris.h"

bool line_is_empty(char *str)
{
    for (int i = 0; str[i]; i++) {
        if (str[i] == '*')
            return (false);
    }
    return (true);
}

bool colomun_is_empty(char **str, int count, int j)
{
    int i = 0;

    while (i <= count) {
        if (str[i][j] == '*')
            return false;
        i++;
    }
    return true;
}

char **delete_too_much_line(char **arr)
{
    int i;

    while (arr[0] && line_is_empty(arr[0]) == true) {
        arr = delete_line_array(arr, 0);
        if (!arr)
            return (NULL);
    }
    if (!arr[0])
        return (arr);
    i = my_arraylen(arr) - 1;
    while (arr[i] && line_is_empty(arr[i]) == true) {
        arr = delete_line_array(arr, i);
        if (!arr)
            return (NULL);
        i--;
    }
    return (arr);
}
