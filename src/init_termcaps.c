/*
** EPITECH PROJECT, 2019
** init_termcas
** File description:
** tetris
*/

#include "tetris.h"

char *get_next_env(char *str)
{
    int i = 0;
    char *res = malloc(sizeof(char) * (my_strlen(str) + 1));

    if (!res)
        return (NULL);
    for (; str[i] && str[i] != '='; i++)
        res[i] = str[i];
    res[i] = '\0';
    return (res);
}

char *value_of_env(char *str)
{
    int a = 0;
    int i = 0;
    char *res = malloc(sizeof(char) * (my_strlen(str) + 1));

    if (!res)
        return (NULL);
    for (; str[i] && str[i] != '='; i++);
    if (!str[i])
        return (NULL);
    i++;
    for (; str[i]; i++, a++)
        res[a] = str[i];
    res[a] = '\0';
    return (res);
}

char *my_getenv(char *str, char **env)
{
    char *s;

    for (int i = 0; env[i]; i++) {
        s = get_next_env(env[i]);
        if (!s)
            return (NULL);
        if (my_strcmp(s, str) == 0)
            return (value_of_env(env[i]));
        free(s);
    }
    return (NULL);
}

int init_termcaps(char **env)
{
    char *term = my_getenv("TERM", env);

    if (!term)
        return (FAILURE);
    if (setupterm(term, 1, NULL) == -1)
        return (FAILURE);
    return (SUCCESS);
}