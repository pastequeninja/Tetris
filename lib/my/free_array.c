/*
** EPITECH PROJECT, 2019
** free_array.c
** File description:
** lib
*/

#include "my.h"

void free_array(char **arr)
{
    for (int i = 0; arr[i]; i++)
        free(arr[i]);
    free(arr);
}