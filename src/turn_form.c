/*
** EPITECH PROJECT, 2019
** turn_form
** File description:
** tetris
*/

#include "tetris.h"

int max_line(char **arr)
{
    int len;
    int count = 0;

    for (int i = 0; arr[i]; i++) {
        len = my_strlen(arr[i]);
        if (len > count)
            count = len;
    }
    return (count + 1);
}

char **malloc_form(char **tmp)
{
    int max_l = max_line(tmp);
    char **res = malloc(sizeof(char *) * max_l);

    if (!res)
        return (NULL);
    for (int i = 0; i < max_l; i++) {
        res[i] = malloc(sizeof(char) * (my_arraylen(tmp) + 1));
        if (!res[i])
            return (NULL);
    }
    res[max_l - 1] = NULL;
    return (res);
}

char *fill_line_form(char *str, char **tmp, int i)
{
    int i_str = 0;

    for (int a = 0; tmp[a]; a++) {
        if (my_strlen(tmp[a]) <= i)
            str[i_str] = ' ';
        else
            str[i_str] = tmp[a][i];
        i_str++;
    }
    str[i_str] = '\0';
    return (str);
}

actual_form_t *turn_form(actual_form_t *form, map_game_t *map_game, \
game_mode_t game_mode)
{
    int max_l;
    char **tmp = my_arraydup(form->figure);

    if (!tmp)
        return (NULL);
    max_l = max_line(tmp);
    free_array(form->figure);
    if (!(form->figure = malloc_form(tmp)))
        return (NULL);
    max_l -= 2;
    for (int i = 0; max_l >= 0; i++) {
        form->figure[i] = fill_line_form(form->figure[i], tmp, max_l);
        max_l--;
    }
    if (touch_a_form(form, map_game, game_mode) == true) {
        free_array(form->figure);
        form->figure = my_arraydup(form->form->figure);
        if (!form->figure)
            return (NULL);
    }
    return (form);
}