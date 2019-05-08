/*
** EPITECH PROJECT, 2019
** structs of minishell
** File description:
** Mai Ly Lehoux
*/

#ifndef FORM_H_
#define FORM_H_

#include "my.h"

typedef struct form_s {
    int x;
    int y;
    int color;
    char *size;
    char *name;
    char *form;
    char **figure;
    struct form_s *next;
    struct form_s *prev;
}form_t;

#endif
