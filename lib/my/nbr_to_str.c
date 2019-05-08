/*
** EPITECH PROJECT, 2019
** nbr_to_str
** File description:
** matchsticlk
*/

#include <stddef.h>
#include <stdlib.h>

int my_nbrlen(int nb);

char *nbr_to_str(int nb)
{
    int i = 0;
    int power = 1;
    char *result = malloc(sizeof(char) * (my_nbrlen(nb) + 1));

    if (!result)
        return (NULL);
    while (nb / power > 9)
        power *= 10;
    while (power != 1) {
        result[i] = nb / power + '0';
        nb %= power;
        power /= 10;
        i++;
    }
    result[i] = nb + '0';
    result[i + 1] = '\0';
    return (result);
}
