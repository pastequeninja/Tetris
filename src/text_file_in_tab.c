/*
** EPITECH PROJECT, 2019
** init_map.c
** File description:
** my_rpg
*/

#include "tetris.h"

char **text_file_in_tab(char *path)
{
    FILE *fd = fopen(path, "r");
    char **result = malloc(sizeof(char *) * 1);
    char *str = NULL;
    size_t size = 1;

    if (!fd || !result)
        return (NULL);
    result[0] = NULL;
    for (int i = 0; getline(&str, &size, fd) != -1; i++) {
        if (str[my_strlen(str) - 1] == '\n')
            str[my_strlen(str) - 1] = '\0';
        if (!(result = my_realloc_array(result, 1)))
            return (NULL);
        if (!(result[i] = my_strdup(str)))
            return (NULL);
        result[i + 1] = NULL;
    }
    if (fclose(fd) != 0)
        return (NULL);
    return (result);
}
