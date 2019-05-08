/*
** EPITECH PROJECT, 2019
** my_swap
** File description:
** lib
*/

void my_swap(int *a, int *b)
{
    int p;

    p = *b;
    *b = *a;
    *a = p;
}