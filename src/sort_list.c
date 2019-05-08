/*
** EPITECH PROJECT, 2019
** sort_list
** File description:
** tetris
*/

#include "tetris.h"

form_t *last_connect(form_t *first, form_t *current)
{
    if (first->prev)
        first->prev->next = first;
    if (first->next)
        first->next->prev = first;
    if (current->prev)
        current->prev->next = current;
    if (current->next)
        current->next->prev = current;
    return (current);
}

form_t *sort_first_and_current(form_t *first, form_t *current, int i, int *n)
{
    form_t *first_prev = first->prev;
    form_t *first_next = first->next;

    if (i == 1)
        return (first);
    first->next = current->next;
    if (*n != 0) {
        first->prev = current->prev;
        current->next = first_next;
    } else {
        first->prev = current;
        current->next = first;
    }
    current->prev = first_prev;
    *n = 0;
    return (last_connect(first, current));
}

void sort_list(form_t *form)
{
    int i = 0;
    form_t *first = form;
    form_t *current = form;

    for (; first->next; first = first->next) {
        current = first->next;
        for (int n = 0; current; current = current->next, n++) {
            i = compare_two_str(first->name, current->name);
            first = sort_first_and_current(first, current, i, &n);
        }
    }
}
