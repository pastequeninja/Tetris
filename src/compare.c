/*
** EPITECH PROJECT, 2019
** compare
** File description:
** sort list
*/

int compare_two_ch(char ch1, char ch2)
{
    if (ch1 <= 'z' && ch1 >= 'a')
        ch1 -= 32;
    if (ch2 <= 'z' && ch2 >= 'a')
        ch2 -= 32;
    if (ch1 < ch2)
        return (1);
    if (ch1 > ch2)
        return (2);
    return (0);
}

int compare_two_str(char *str1, char *str2)
{
    int i = 0;

    while (str1[i] != '\0' && str2[i] != '\0') {
        if (compare_two_ch(str1[i], str2[i]) == 1)
            return (1);
        if (compare_two_ch(str1[i], str2[i]) == 2)
            return (2);
        i++;
        if (str1[i] == '\0')
            return (1);
        if (str2[i] == '\0')
            return (2);
    }
    return (1);
}