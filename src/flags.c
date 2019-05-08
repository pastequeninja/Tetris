/*
** EPITECH PROJECT, 2019
** check arguments for debug mode
** File description:
** Mai Ly Lehoux
*/

#include "tetris.h"

const struct option long_options[] = {
    {"debug", no_argument, 0, 'D'},
    {"help", no_argument, 0, 'h'},
    {"level", required_argument, 0, 'L'},
    {"without-next", no_argument, 0, 'w'},
    {"map-size", required_argument, 0, 'm'},
    {"key-left", required_argument, 0, 'l'},
    {"key-right", required_argument, 0, 'r'},
    {"key-turn", required_argument, 0, 't'},
    {"key-drop", required_argument, 0, 'd'},
    {"key-quit", required_argument, 0, 'q'},
    {"key-pause", required_argument, 0, 'p'},
    {0, 0, 0, 0}
};

int flags_info_check(int opt, char **av)
{
    if (opt == 'h') {
        print_help(av);
        return 1;
    }
    return 0;
}

char *change_key(char *opt_arg, char *key)
{
    char *remplace = my_strdup("^E");
    char *new_key = my_strdup(opt_arg);
    int i = 0;
    int rep = 0;
    int j = 0;

    if (new_key == NULL)
        return NULL;
    while (key[i] != '\0') {
        if (key[i] == 27 || rep == 1) {
            rep = 1;
            new_key[j] = opt_arg[i];
            j++;
        }
        i++;
    }
    if ((new_key = my_strdupcat(remplace, new_key)) == NULL)
        return NULL;
    return new_key;
}

void putstr_key(char *str)
{
    for (int i = 0; str[i]; i++) {
        if (str[i] == 27)
            my_putstr("^E");
        else if (str[i] == ' ')
            my_putstr("(space)");
        else
            my_putchar(str[i]);
    }
}

int check_arguments(int ac, char **av, game_mode_t *game)
{
    int opt = 0;
    int long_index = 0;
    int flags_display = 0;
    int stop_game = 0;

    while ((opt = getopt_long(ac, av, "DhL:wm:l:r:t:d:q:p:", \
    long_options, &long_index)) != -1) {
        if ((flags_display = flags_info_check(opt, av)) == 1)
            return 1;
        stop_game = switch_flags(opt, game);
        if (stop_game == 84)
            return 84;
    }
    if (optind != ac)
        return 84;
    return 0;
}
