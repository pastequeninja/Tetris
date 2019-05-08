/*
** EPITECH PROJECT, 2019
** bootstrap
** File description:
** m
*/

#include "tetris.h"

void display(form_t *form)
{
    for (; form->prev != NULL; form = form->prev);
    for (; form != NULL; form = form->next) {
        my_putstr(form->size);
    }
    my_putchar('\n');
}

char *user_event(form_t *form, game_mode_t game)
{
    char *buff = malloc(sizeof(char) * 3);

    if (buff == NULL)
        return NULL;
    print_debug_mode(form, game);
    my_putstr("Press any key to start Tetris");
    term_mode(CANONIQUE);
    while (1) {
        if (read(0, buff, 3) >= 0)
            break;
        else
            return buff;
    }
    term_mode(NORMAL);
    return buff;
}

int tetris(int ac, char **av, char **env)
{
    form_t *all_forms = fill_struct();
    game_mode_t game_mode;
    int arguments = 0;

    if (all_forms == NULL)
        return 84;
    if (init_termcaps(env) == FAILURE)
        return (FAILURE_EXIT);
    keypad(stdscr, TRUE);
    if (init_game_mode(&game_mode) == FAILURE)
        return (FAILURE_EXIT);
    arguments = check_arguments(ac, av, &game_mode);
    if (arguments == 1)
        return 0;
    if (arguments == 84)
        return 84;
    sort_list(all_forms);
    if (game_mode.display_debug == true)
        if (user_event(all_forms, game_mode) == NULL)
            return 84;
    return (begin_game(all_forms, game_mode));
}

int main(int ac, char **av, char **env)
{
    return (tetris(ac, av, env));
}
