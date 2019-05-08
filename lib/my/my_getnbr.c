/*
** EPITECH PROJECT, 2018
** my_getnbr.c
** File description:
** getnbr from a string.
*/

#include <stdlib.h>

int my_getnbr(char const *str)
{
    int power = 1;
    int nbr = 0;
    int neg = 1;
    int i = 0;

    while (str[i] == '-') {
        neg = neg * (-1);
        i++;
    }
    while (str[i + 1] != '\0') {
        i++;
        power = power * 10;
    }
    i = (neg < 0 ? -neg : 0);
    while (str[i] !='\0' && str[i] >= '0' && str[i] <= '9') {
        nbr = nbr + (str[i] - 48) * power;
        power = power / 10;
        i++;
    }
    return (nbr * neg);
}