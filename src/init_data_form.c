/*
** EPITECH PROJECT, 2019
** tetris
** File description:
** l
*/

#include "tetris.h"

form_t *fill_params(char *str, form_t *form)
{
    char **all_nbrs = str_to_word_array(str);

    form->x = my_getnbr(all_nbrs[0]);
    form->y = my_getnbr(all_nbrs[1]);
    for (int i = 0; all_nbrs[2][i]; i++) {
        if (all_nbrs[2][i] == '\n') {
            all_nbrs[2][i] = '\0';
            break;
        }
    }
    form->color = my_getnbr(all_nbrs[2]);
    free_array(all_nbrs);
    return form;
}

form_t *fill_form(int fd, form_t *form)
{
    char *tmp = malloc(sizeof(char) * (stats(fd) + 1));

    if (tmp == NULL)
        return NULL;
    if (read(fd, tmp, stats(fd)) == -1)
        return NULL;
    tmp[stats(fd)] = '\0';
    if (parse_map(tmp, &(form->form)) == 84) {
        if ((form->size = my_strdup("error")) == NULL)
            return NULL;
        return form;
    }
    form = fill_params(tmp, form);
    if (check_real_form_size(form->x, form->y, form->figure) == 84) {
        if ((form->size = my_strdup("error")) == NULL)
            return NULL;
        return form;
    }
    form->size = NULL;
    return form;
}

char *fill_tmp(int j, int i, char **form)
{
    int save = j;
    char *tmp = malloc(sizeof(char) * my_strlen(form[i]) + 1);

    j = 0;
    if (form == NULL)
        return NULL;
    while (form[i][save] != '\0') {
        tmp[j] = form[i][save];
        j++;
        save++;
    }
    tmp[j] = '\0';
    return tmp;
}

form_t *fill_data(char *file_name, form_t *form)
{
    int fd = 0;
    char *complete_name = NULL;

    complete_name = my_strdup("tetriminos/");
    if ((complete_name = my_strdupcat(complete_name, file_name)) == NULL)
        return NULL;
    if (complete_name == NULL)
        return NULL;
    if ((fd = open(complete_name, O_RDONLY)) == -1)
        return NULL;
    if ((form = configure_figure(form, complete_name)) == NULL)
        return NULL;
    if ((form->name = new_name(file_name)) == NULL)
        return NULL;
    if ((form = fill_form(fd, form)) == NULL)
        return NULL;
    if (close(fd) == -1)
        return (NULL);
    if ((form->next = malloc(sizeof(form_t))) == NULL)
        return NULL;
    return (form);
}
