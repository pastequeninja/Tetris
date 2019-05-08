/*
** EPITECH PROJECT, 2018
** task04 / Day05
** File description:
** my_compute_power_rec
*/

int my_compute_power_rec(int nb, int p)
{
    int r = 0;

    if (p < 0)
        return (0);
    if (p == 0)
        return (1);
    else {
        r = nb * my_compute_power_rec(nb, p - 1);
        return (r);
    }
}
