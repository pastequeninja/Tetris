/*
** EPITECH PROJECT, 2019
** tetris
** File description:
** config
*/

#include "tetris.h"

char **fill_form_without_space(char **form, int j, int max_line)
{
    char **tmp = my_arraydup(form);
    int i = 0;
    int b = 0;
    char *tmp_2 = NULL;

    if (tmp == NULL)
        return NULL;
    free_array(form);
    if ((form = malloc(sizeof(char *) * (my_arraylen(tmp) + 1))) == NULL)
        return NULL;
    while (i <= max_line) {
        if ((tmp_2 = fill_tmp(j, i, tmp)) == NULL)
            return NULL;
        if ((form[b] = my_strdup(tmp_2)) == NULL)
            return NULL;
        i++;
        b++;
    }
    form[b] = NULL;
    return form;
}

char **delete_spaces(char **form)
{
    int i = 0;
    int count = 0;
    int j = 0;

    while (form[count] != NULL)
        count++;
    count -= 1;
    while (form[i] != NULL && colomun_is_empty(form, count, j) == true) {
        if (i == count) {
            i = 0;
            j++;
        }
        else
            i++;
    }
    form = fill_form_without_space(form, j, count);
    return form;
}

char *delete_extension(char *file_name, char *tmp)
{
    int i = 0;

    while (file_name[i] != '\0') {
        if (i != 0 && file_name[i] == '.' && file_name[i + 1] != '\0' && \
            file_name[i + 1] == 't' && file_name[i + 2] != '\0' && \
            file_name[i + 2] == 'e' && file_name[i + 3] != '\0' && \
            file_name[i + 3] == 't' && file_name[i + 4] != '\0' && \
            file_name[i + 4] == 'r' && file_name[i + 10] == '\0') {
            break;
        }
        tmp[i] = file_name[i];
        i++;
    }
    tmp[i] = '\0';
    return tmp;
}

char *new_name(char *file_name)
{
    int i = 0;
    char *tmp = NULL;

    if ((tmp = malloc(sizeof(char) * my_strlen(file_name) + 1)) == NULL)
        return NULL;
    if (file_name[i] == '.' && file_name[i + 1] != '\0' && \
        file_name[i + 1] == 't' && file_name[i + 2] != '\0' && \
        file_name[i + 2] == 'e' && file_name[i + 3] != '\0' && \
        file_name[i + 3] == 't' && file_name[i + 4] != '\0' && \
        file_name[i + 4] == 'r' && file_name[i + 10] == '\0') {
        tmp[0] = '\0';
        return tmp;
    }
    return delete_extension(file_name, tmp);
}

form_t *configure_figure(form_t *form, char *complete_name)
{
    if (!(form->figure = text_file_in_tab(complete_name)))
        return (NULL);
    if (!(form->figure = delete_line_array(form->figure, 0)))
        return (NULL);
    if ((form->figure = delete_too_much_line(form->figure)) == NULL)
        return NULL;
    if ((form->figure = delete_spaces(form->figure)) == NULL)
        return NULL;
    return form;
}
