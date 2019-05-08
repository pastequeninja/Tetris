/*
** EPITECH PROJECT, 2018
** task10 / Day06
** File description:
** isalpha
*/

int my_str_isalpha(char const *str)
{
    int i = 0;

    while (str[i] != '\0') {
        if (str[i] > 64 && str[i] < 91)
            return (0);
        if (str[i] > 96 && str[i] < 123)
            return (0);
        if (str[i] > 47 && str[i] < 58)
            return (0);
        i++;
    }
    return (1);
}
