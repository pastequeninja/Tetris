/*
** EPITECH PROJECT, 2018
** task03 / Day06
** File description:
** my_revstr
*/

char *my_revstr(char *str)
{
    int i = 0;
    int a = 0;
    char p = 'o';

    while (str[i] != '\0')
        i++;
    i = i - 1;
    while (i > a) {
        p = str[i];
        str[i] = str[a];
        str[a] = p;
        a++;
        i--;
    }
    return (str);
}
