/*
** EPITECH PROJECT, 2018
** task05 / Day 05
** File description:
** my_compute_square_root
*/

int my_compute_square_root(int nb)
{
    int i = 1;

    if (nb == 1)
        return (1);
    if (nb <= 0)
        return (0);
    while (i != nb) {
        if ((i * i) == nb)
            return (i);
        i++;
    }
    return (0);
}
