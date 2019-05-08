/*
** EPITECH PROJECT, 2018
** task 08 / Day06
** File description:
** strlowcase
*/

char *my_strlowcase(char *str)
{
    int i = 0;

    while (str[i] != '\0') {
        if (str[i] > 64 && str[i] < 91)
            str[i] = str[i] + 32;
        i++;
    }
    return (str);
}
