/*
** EPITECH PROJECT, 2018
** task05/Day06
** File description:
** my_strcmp
*/

int my_strlen(char const *str);

int str_cmp(char *s1, char *s2)
{
    int i = 0;

    while (s1[i] != '\0' && s2[i] != '\0') {
        if (s1[i] < s2[i])
            return (-1);
        if (s1[i] > s2[i])
            return (1);
        i++;
    }
    return (0);
}

int my_strcmp(char *s1, char *s2)
{
    if (!s1 || !s2)
        return (1);
    if (my_strlen(s1) == my_strlen(s2))
        return (str_cmp(s1, s2));
    else if (my_strlen(s1) > my_strlen(s2))
        return (1);
    else
        return (-1);
}
