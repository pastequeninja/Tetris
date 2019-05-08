/*
** EPITECH PROJECT, 2019
** Maily Lehoux
** File description:
** lib
*/

#include "../../include/my.h"

int ct_malloc(char *str)
{
    int i = 0;
    int j = 0;

    while (str[i] != '\0') {
        if (str[i] == ' ')
            j++;
        i++;
    }
    return (j + 2);
}

int ct_malloc_2(char *str, int i)
{
    while (str[i] != '\0' && str[i] != ' ')
        i++;
    return (i + 1);
}

char **str_parse_double(char *str)
{
    char **arr = malloc(sizeof(char *) * ct_malloc(str));
    int x = 0;
    int y = 0;
    int i = 0;

    if (str == NULL)
        return NULL;
    for (; str[i] != '\0'; x++) {
        for (; str[i] != '\0' && (str[i] == ' ' || str[i] == '\n'); i++);
        if (str[i] == '\0')
            continue;
        if ((arr[x] = malloc(sizeof(char) * ct_malloc_2(str, i))) == NULL)
            return (NULL);
        for (y = 0; str[i] != '\0' && str[i] != ' ' && str[i] != '\n'; y++, i++)
            arr[x][y] = str[i];
        arr[x][y] = '\0';
    }
    arr[x] = NULL;
    return (arr);
}
