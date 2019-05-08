/*
** EPITECH PROJECT, 2019
** actual_form
** File description:
** tretris
*/

#ifndef ACTUAL_FORM_H
#define ACTUAL_FORM_H

#include "tetris.h"

typedef struct actual_form_s {
    form_t *form;
    char **figure;
    int x;
    int y;
} actual_form_t;

#endif