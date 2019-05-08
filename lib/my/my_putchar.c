/*
** EPITECH PROJECT, 2018
** my_puchar
** File description:
** lib
*/

#include <unistd.h>

void my_putchar(char c)
{
    write(1, &c, 1);
}
