/*
** EPITECH PROJECT, 2019
** my_putchar_error
** File description:
** lib
*/

#include <unistd.h>

void my_putchar_error(char c)
{
    write(2, &c, 1);
}