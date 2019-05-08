/*
** EPITECH PROJECT, 2019
** my_strdup
** File description:
** lib
*/

#include <stddef.h>
#include <stdlib.h>

int my_strlen(char *);
char *my_strcpy(char *, char *);

char *my_strdup(char *str)
{
    char *result = NULL;

    if (!str)
        return (NULL);
    if (!(result = malloc(sizeof(char) * (my_strlen(str) + 1))))
        return (NULL);
    result = my_strcpy(result, str);
    return (result);
}
