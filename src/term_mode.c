/*
** EPITECH PROJECT, 2019
** tetr_mode
** File description:
** tetris
*/

#include "tetris.h"

int term_mode(int i)
{
    static struct termios old_mode;
    static struct termios new_mode;

    if (i == GAME || i == CANONIQUE) {
        ioctl(0, TCGETS, &old_mode);
        ioctl(0, TCGETS, &new_mode);
        new_mode.c_lflag &= ~ECHO;
        new_mode.c_lflag &= ~ICANON;
        if (i == GAME) {
            new_mode.c_cc[VMIN] = 0;
            new_mode.c_cc[VTIME] = 0;
        }
        ioctl(0, TCSETS, &new_mode);
    }
    if (i == NORMAL) {
        ioctl(0, TCSETS, &old_mode);
    }
    return (SUCCESS);
}
