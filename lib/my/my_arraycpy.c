/*
** EPITECH PROJECT, 2019
** my_arraycpy
** File description:
** lib
*/

#include "my.h"

char **my_arraycpy(char **dest, char **src)
{
    for (int i = 0; src[i]; i++)
        dest[i] = my_strcpy(dest[i], src[i]);
    return (dest);
}