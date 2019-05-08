/*
** EPITECH PROJECT, 2019
** chekc_real_form_size
** File description:
** tetris
*/

#include "tetris.h"

int check_every_line(char *figure)
{
    int i = 0;
    int n = 0;

    while (figure[i] != '\0') {
        for (n = i; figure[n] == ' '; n++);
        if (figure[n])
            i += (n - i) + 1;
        else
            return (i);
    }
    return (i);
}

int check_real_form_size(int x, int y, char **figure)
{
    int i = 0;
    int most_line = 0;
    int j = 0;

    while (figure[i] != NULL)
        i++;
    if (y != i)
        return 84;
    i = 0;
    while (figure[j] != NULL) {
        i = check_every_line(figure[j]);
        if (i >= most_line)
            most_line = i;
        i = 0;
        j++;
    }
    if (x != most_line)
        return 84;
    return 0;
}