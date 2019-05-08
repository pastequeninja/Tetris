/*
** EPITECH PROJECT, 2019
** my_strdupcat
** File description:
** lib
*/

#include "my.h"

char *my_strdupcat(char *dest, char *src)
{
    int size = my_strlen(dest) + my_strlen(src);
    char *tmp = NULL;

    if (dest) {
        if (!(tmp = my_strdup(dest)))
            return (NULL);
        free(dest);
    }
    if (!(dest = malloc(sizeof(char) * (size + 3))))
        return (NULL);
    dest[0] = '\0';
    if (tmp) {
        dest = my_str_cat(dest, tmp);
        free(tmp);
    }
    dest = my_str_cat(dest, src);
    return (dest);
}