/*
** EPITECH PROJECT, 2019
** tetris
** File description:
** switch flags
*/

#include "tetris.h"

int switch_flags3(int opt, game_mode_t *game)
{
    switch (opt) {
    case 'd' :
        game->k_drop = my_strdup(optarg);
        break;
    case 'q' :
        game->k_quit = my_strdup(optarg);
        break;
    case 'p' :
        game->k_pause = my_strdup(optarg);
        break;
    default :
        return 84;
    }
    if (my_strlen(optarg) == 0)
        return (84);
    return 0;
}

int switch_flags2(int opt, game_mode_t *game)
{
    switch (opt) {
    case 'l' :
        game->k_left = my_strdup(optarg);
        break;
    case 'r' :
        game->k_right = my_strdup(optarg);
        break;
    case 't' :
        game->k_turn = my_strdup(optarg);
        break;
    default :
        return (switch_flags3(opt, game));
    }
    if (my_strlen(optarg) == 0)
        return (84);
    return 0;
}

int switch_flags(int opt, game_mode_t *game)
{
    switch (opt) {
    case 'L' :
        if (good_level(optarg) == false)
            return (84);
        game->level = my_getnbr(optarg);
        break;
    case 'w' :
        game->display_next = false;
        break;
    case 'm' :
        return (change_size_map(game, optarg));
    case 'D' :
        game->display_debug = true;
        break;
    default :
        return (switch_flags2(opt, game));
    }
    return 0;
}
