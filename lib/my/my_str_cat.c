/*
** EPITECH PROJECT, 2019
** my_str_cat
** File description:
** lib
*/

char *my_str_cat(char *dest, char const *src)
{
    int i = 0;
    int a = 0;

    if (!src)
        return (dest);
    while (dest[i] != '\0')
        i++;
    while (src[a] != '\0') {
        dest[i] = src[a];
        a++;
        i++;
    }
    dest[i] = '\0';
    return (dest);
}
