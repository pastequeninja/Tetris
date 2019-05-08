/*
** EPITECH PROJECT, 2019
** my nbrlen
** File description:
** lib
*/

int my_nbrlen(int nb)
{
    int count = 1;

    while (nb > 9) {
        nb /= 10;
        count++;
    }
    return (count);
}