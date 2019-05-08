/*
** EPITECH PROJECT, 2019
** begin_game
** File description:
** tetris
*/

#include "tetris.h"

void init_all_color(void)
{
    init_color(COLOR_WHITE, 1000, 1000, 1000);
    init_color(COLOR_RED, 1000, 0, 0);
    init_color(COLOR_BLUE, 0, 0, 1000);
    init_color(COLOR_YELLOW, 1000, 1000, 0);
    init_color(COLOR_GREEN, 0, 1000, 0);
    init_color(COLOR_CYAN, 0, 1000, 1000);
    init_color(COLOR_MAGENTA, 1000, 0, 1000);
    init_pair(1, COLOR_RED, COLOR_BLACK);
    init_pair(2, COLOR_GREEN, COLOR_BLACK);
    init_pair(3, COLOR_YELLOW, COLOR_BLACK);
    init_pair(4, COLOR_BLUE, COLOR_BLACK);
    init_pair(5, COLOR_MAGENTA, COLOR_BLACK);
    init_pair(6, COLOR_CYAN, COLOR_BLACK);
    init_pair(7, COLOR_WHITE, COLOR_BLACK);
}

void init_window(void)
{
    initscr();
    start_color();
    noecho();
    cbreak();
    nodelay(stdscr, TRUE);
    init_all_color();
    keypad(stdscr, TRUE);
    curs_set(0);
}

int form_len(form_t *form)
{
    int count = 0;

    while (form) {
        if (my_strcmp(form->size, "error") != 0)
            count++;
        form = form->next;
    }
    return (count);
}

void delete_error_forms(form_t *form)
{
    for (; form; form = form->next) {
        if (my_strcmp(form->size, "error") != 0) {
            continue;
        }
        if (form->prev)
            form->prev->next = form->next;
        if (form->next)
            form->next->prev = form->prev;
    }
}

int begin_game(form_t *form, game_mode_t game_mode)
{
    int nb_form;
    display_t *display = NULL;

    delete_error_forms(form);
    for (; form->next; form = form->next);
    for (; form->prev; form = form->prev);
    display = init_display(game_mode, form);
    if (!display)
        return (84);
    init_window();
    srand(time(NULL));
    display_the_game(display, game_mode);
    delete_error_forms(form);
    nb_form = form_len(form);
    init_level_begin(&game_mode);
    calculate_size_display(display);
    if (play_game(form, nb_form, game_mode, display) == FAILURE)
        return (FAILURE_EXIT);
    endwin();
    return (SUCCESS_EXIT);
}
