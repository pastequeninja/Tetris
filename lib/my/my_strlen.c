/*
** EPITECH PROJECT, 2018
** task03 / Day04
** File description:
** my_strlen
*/

int my_strlen(char const *str)
{
    int i = 0;

    if (!str)
        return (0);
    while (str[i] != '\0')
        i++;
    return (i);
}
