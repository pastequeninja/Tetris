/*
** EPITECH PROJECT, 2019
** my_put_nbr_eror
** File description:
** lib
*/

#include <unistd.h>

void my_putchar_error(char c);

void my_put_nbr_error(int nb)
{
    if (nb < 0) {
        my_putchar_error('-');
        nb *= -1;
    }
    if (nb > 9)
        my_put_nbr_error(nb / 10);
    my_putchar_error(nb % 10 + '0');
}