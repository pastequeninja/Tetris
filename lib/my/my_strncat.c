/*
** EPITECH PROJECT, 2018
** task03 / Day07
** File description:
** my_strncat
*/

char *my_strncat(char *dest, char const *src, int nb)
{
    int i = 0;
    int a = 0;

    while (dest[i] != '\0')
        i++;
    while (i != nb + 1) {
        dest[i] = src[a];
        a++;
        i++;
    }
    return (dest);
}
