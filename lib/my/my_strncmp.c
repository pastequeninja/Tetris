/*
** EPITECH PROJECT, 2018
** task06/Day06
** File description:
** strncmp
*/

int my_strncmp(char const *s1, char const *s2, int n)
{
    int i = 0;
    int a = 0;

    while (a < n) {
        if (s1[i] < s2[i])
            return (-1);
        if (s1[i] > s2[i])
            return (1);
        a++;
        i++;
    }
    return (0);
}
