/*
** EPITECH PROJECT, 2019
** str_to_word_array.c
** File description:
** lib
*/

#include <unistd.h>
#include <stdlib.h>

int check_nb_line(char *str)
{
    int i = 0;
    int nb_line = 0;

    for (; str[i] && (str[i] == ' ' || str[i] == '\t'); i++);
    while (str[i]) {
        for (; str[i] != '\0' && str[i] != ' ' && str[i] != '\t'; i++);
        nb_line++;
        for (; str[i] != '\0' && (str[i] == ' ' || str[i] == '\t'); i++);
    }
    return (nb_line);
}

int next(char *str, int i)
{
    int count = 0;

    for (; str[i] && str[i] != ' ' && str[i] != '\t'; i++)
        count++;
    return (count + 1);
}

char **str_to_word_array(char *str)
{
    int i = 0;
    int col = 0;
    int line = 0;
    int nb_line = check_nb_line(str);
    char **array = NULL;

    if (nb_line == 0 || !(array = malloc(sizeof(char *) * (nb_line + 1))))
        return (NULL);
    for (; str[i] && (str[i] == ' ' || str[i] == '\t'); i++);
    while (str[i]) {
        if (!(array[col] = malloc(sizeof(char) * (next(str, i) + 2))))
            return (NULL);
        for (line = 0; str[i] && str[i] != ' ' && str[i] != '\t'; i++, line++)
            array[col][line] = str[i];
        array[col][line] = '\0';
        col++;
        for (; str[i] && (str[i] == ' ' || str[i] == '\t'); i++);
    }
    array[col] = NULL;
    return (array);
}
