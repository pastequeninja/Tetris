/*
** EPITECH PROJECT, 2019
** my_puterror
** File description:
** lib
*/

#include <unistd.h>

int my_strlen(char *str);

void my_puterror(char *str)
{
    write(2, str, my_strlen(str));
}
