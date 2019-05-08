/*
** EPITECH PROJECT, 2019
** tetris
** File description:
** fill ll
*/

#include "tetris.h"

int stats(int fd)
{
    struct stat buff;

    fstat(fd, &buff);
    off_t size = buff.st_size;
    return size;
}

bool is_a_bad_name(char *str)
{
    char buffer[] = "tetrimino";
    int i = my_strlen(str);
    int n = 8;

    if (i < 9)
        return (true);
    i--;
    for (; str[i] && str[i] != '.'; i--, n--) {
        if (str[i] != buffer[n])
            return (true);
    }
    if (!str[i])
        return (true);
    return (false);
}

form_t *read_directory(form_t *forms, DIR *dir)
{
    struct dirent *dp;

    while ((dp = readdir(dir)) != NULL) {
        if (is_a_bad_name(dp->d_name) == true)
            continue;
        if ((forms = fill_data(dp->d_name, forms)) == NULL)
            return NULL;
        forms->next->prev = forms;
        forms = forms->next;
    }
    return forms;
}

form_t *fill_struct(void)
{
    form_t *forms = malloc(sizeof(form_t));
    DIR *dir;

    if (forms == NULL)
        return NULL;
    forms->prev = NULL;
    if ((dir = opendir("tetriminos")) == NULL)
        return NULL;
    if ((forms = read_directory(forms, dir)) == NULL)
        return NULL;
    if (closedir(dir) == -1)
        return NULL;
    if (forms->prev == NULL)
        return NULL;
    forms = forms->prev;
    free(forms->next);
    forms->next = NULL;
    for (; forms->prev != NULL; forms = forms->prev);
    return forms;
}
