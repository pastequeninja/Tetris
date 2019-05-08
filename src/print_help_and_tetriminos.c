/*
** EPITECH PROJECT, 2019
** tetris
** File description:
** print help and data of tetriminos
*/

#include "tetris.h"

void print_forms_data(form_t *form)
{
    my_putstr("Tetriminos : ");
    my_putstr("Name ");
    my_putstr(form->name);
    my_putstr(" : ");
    if (my_strcmp(form->size, "error") == 0) {
        my_putstr("Error\n");
        return;
    }
    my_putstr("Size ");
    my_put_nbr(form->x);
    my_putchar('*');
    my_put_nbr(form->y);
    my_putstr(" : ");
    my_putstr("Color ");
    my_put_nbr(form->color);
    my_putstr(" :\n");
    my_putarray(form->figure);
}

void nbr_of_tetriminos(form_t *form)
{
    int i = 0;

    for (; form->prev != NULL; form = form->prev);
    for (; form->next != NULL; form = form->next)
        i++;
    my_put_nbr(i + 1);
    my_putchar('\n');
    for (; form->prev != NULL; form = form->prev);
    for (; form != NULL; form = form->next)
        print_forms_data(form);
}

void print_debug_mode2(form_t *form, game_mode_t game)
{
    my_putstr("\nLevel : ");
    my_put_nbr(game.level);
    my_putstr("\nSize : ");
    my_put_nbr(game.size_x);
    my_putchar('*');
    my_put_nbr(game.size_y);
    my_putstr("\nTetriminos : ");
    nbr_of_tetriminos(form);
}

void print_debug_mode(form_t *form, game_mode_t game)
{
    my_putstr("*** DEBUG MODE ***\n");
    my_putstr("Key Left : ");
    putstr_key(game.k_left);
    my_putstr("\nKey Right : ");
    putstr_key(game.k_right);
    my_putstr("\nKey Turn : ");
    putstr_key(game.k_turn);
    my_putstr("\nKey Drop : ");
    putstr_key(game.k_drop);
    my_putstr("\nKey Quit : ");
    putstr_key(game.k_quit);
    my_putstr("\nKey Pause : ");
    putstr_key(game.k_pause);
    my_putstr("\nNext : ");
    if (game.display_next == false)
        my_putstr("No");
    else
        my_putstr("Yes");
    print_debug_mode2(form, game);
}

void print_help(char **av)
{
    my_putstr("Usage : ");
    my_putstr(av[0]);
    my_putstr(" [options]\n");
    my_putstr("Options:\n");
    my_putstr(" --help\t\t\tDisplay this help\n");
    my_putstr(" -L --level={num}\tStart Tetris at level num (def: 1)\n");
    my_putstr(" -l --key-left={K}\tMove the tetrimino LEFT using the K key");
    my_putstr(" (def: left arrow)\n -r --key-right={K}\tMove the tetrimino");
    my_putstr(" RIGHT using the K key (def: right arrow)\n -t --key-turn={K}");
    my_putstr("\tTURN the tetrimino clockwise 90d using the K key (def: top");
    my_putstr(" arrow)\n -d --key-drop={K}\tDROP the tetrimino using the K ");
    my_putstr("key (def: down arrow)\n -q --key-quit={K}\tQUIT the game ");
    my_putstr("using K key (def: 'q' key)\n -p --key-pause={K}\tPAUSE/RESTART");
    my_putstr(" the K key (def: space bar)\n --map-size={row,col}\tSet the ");
    my_putstr("numbers of the map (def: 20, 10)\n -w --without-next\tHide ");
    my_putstr("next tetrimino (def: false)\n -D --debug\t\t");
    my_putstr("Debug mode (def: false)\n");
}
