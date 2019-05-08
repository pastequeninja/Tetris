/*
** EPITECH PROJECT, 2018
** libmy
** File description:
** task01
*/

#ifndef MY_H
#define MY_H

#include <stdlib.h>

void my_putchar(char c);
int my_isneg(int nb);
void my_put_nbr(int nb);
void my_swap(int *a, int *b);
int my_putstr(char const *str);
int my_strlen(char const *str);
int my_compute_power_rec(int nb, int power);
int my_compute_square_root(int nb);
int my_is_prime(int nb);
int my_find_prime_sup(int nb);
char *my_strcpy(char *dest, char const *src);
char *my_strncpy(char *dest, char const *src, int n);
char *my_revstr(char *str);
char *my_strstr(char *str, char const *to_find);
int my_strcmp(char *s1, char *s2);
int my_strncmp(char const *s1, char const *s2, int n);
char *my_strupcase(char *str);
char *my_strlowcase(char *str);
char *my_strcapitalize(char *str);
int my_str_isalpha(char const *str);
char *my_strncat(char *dest, char const *src, int nb);
int complete(int i, int a, char *str);
int my_getnbr(char const *str);
char *my_str_cat(char *dest, char const *src);
int my_nbrlen(int nb);
void my_puterror(char *str);
char **str_to_word_array(char *);
char *my_strdup(char *str);
void my_putchar_error(char c);
void my_put_nbr_error(int nb);
char *nbr_to_str(int);
void free_array(char **);
void my_putarray(char **);
char **my_arraydup(char **);
char **my_arraycpy(char **, char **);
int my_arraylen(char **);
char *my_strdupcat(char *, char *);
char **delete_line_array(char **, int);
char **my_realloc_array(char **, int);

#endif
