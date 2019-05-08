/*
** EPITECH PROJECT, 2019
** init_high_score
** File description:
** tetris
*/

#include "tetris.h"

bool is_an_int(char *str)
{
    for (int i = 0; str[i]; i++) {
        if (str[i] < '0' || str[i] > '9')
            return (false);
    }
    return (true);
}

int init_high_score(void)
{
    int fd = open(".high_score", O_RDONLY);
    char *buff;
    struct stat file;

    if (fd == -1)
        return (0);
    if (fstat(fd, &file) == -1)
        return (0);
    buff = malloc(sizeof(char) * (file.st_size + 1));
    if (!buff)
        return (0);
    if (read(fd, buff, file.st_size) == -1)
        return (0);
    if (close(fd) == -1)
        return (0);
    buff[file.st_size] = '\0';
    if (is_an_int(buff) == false)
        return (0);
    if (my_getnbr(buff) < 0)
        return (0);
    return (my_getnbr(buff));
}