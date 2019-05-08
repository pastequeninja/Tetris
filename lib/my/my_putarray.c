/*
** EPITECH PROJECT, 2019
** my_putarray
** File description:
** lib
*/

#include "my.h"

void my_putarray(char **arr)
{
    for (int i = 0; arr[i]; i++) {
        my_putstr(arr[i]);
        my_putchar('\n');
    }
}