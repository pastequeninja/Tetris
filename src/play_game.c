/*
** EPITECH PROJECT, 2019
** play_game
** File description:
** tetris
*/

#include "tetris.h"

form_t *what_form(form_t *form, int pos)
{
    for (int i = 0; i < pos; i++, form = form->next);
    return (form);
}

actual_form_t *init_actual_form(form_t *form, int nb_form, \
game_mode_t game_mode)
{
    int actual = rand() % nb_form;
    actual_form_t *actual_form = malloc(sizeof(actual_form_t));

    if (!actual_form)
        return (NULL);
    actual_form->form = what_form(form, actual);
    actual_form->figure = my_arraydup(actual_form->form->figure);
    if (!actual_form->figure)
        return (NULL);
    actual_form->x = BEGIN_LINE;
    actual_form->y = (game_mode.size_y - actual_form->form->x) / 2 + \
    BEGIN_COLUMN;
    return (actual_form);
}

void display_board_and_next(game_mode_t game_mode, form_t *next, \
display_t *display, map_game_t *map_game)
{
    int x = BEGIN_LINE + 1;
    int y = (my_strlen(display->next[0]) - next->x) / 2 + game_mode.size_y \
    + 15;

    if (display->size_x_map > LINES || display->size_y_map > COLS)
        bad_dimension(game_mode, display, map_game);
    refresh();
    refesh_the_board();
    display_in_board(game_mode);
    refresh_the_next(display, game_mode);
    attron(COLOR_PAIR(next->color));
    if (game_mode.display_next == true)
        display_smth(next->figure, x, y);
}

int save_the_score(game_mode_t game_mode)
{
    int fd = open(".high_score", O_CREAT | O_WRONLY, S_IRUSR | S_IWUSR | \
    S_IRGRP | S_IWGRP | S_IROTH);
    char *str;

    if (fd == -1)
        return (FAILURE);
    str = nbr_to_str(game_mode.high_score);
    if (!str)
        return (FAILURE);
    write(fd, str, my_strlen(str));
    if (close(fd) == -1)
        return (FAILURE);
    return (SUCCESS);
}

int play_game(form_t *form, int max, game_mode_t game_mode, display_t *display)
{
    actual_form_t *actual_form = init_actual_form(form, max, game_mode);
    form_t *next_form = what_form(form, rand() % max);
    map_game_t *map_game = NULL;

    if (!actual_form)
        return (FAILURE);
    while (analyse_events(map_game, actual_form, &game_mode) != END) {
        display_board_and_next(game_mode, next_form, display, map_game);
        if (form_falls(actual_form, map_game, &game_mode) == \
            NO_TOUCH)
            continue;
        if (!(map_game = put_form_in_map_game(map_game, actual_form)))
            return (FAILURE);
        if (check_line_complete(map_game, &game_mode) == FAILURE)
            return (FAILURE);
        if (change_actual_and_next(actual_form, next_form, game_mode) == -1)
            return (FAILURE);
        next_form = what_form(form, rand() % max);
        map_game = condition_lose(actual_form, map_game, &game_mode);
    }
    return (save_the_score(game_mode));
}
