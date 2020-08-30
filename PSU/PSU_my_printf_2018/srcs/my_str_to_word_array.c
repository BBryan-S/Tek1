/*
** EPITECH PROJECT, 2018
** my_str_to_word_array.c
** File description:
** my_str_to_word_array
*/

#include <stdlib.h>

int check_char(char const c)
{
    if (c < 'A' || (c > 'Z' && c < 'a') || c > 'z')
        if (c < '0' || c > '9')
            return (1);
    return (0);
}

int nb_word(char const *str)
{
    int a = 0;

    for (int b = 0; str != NULL && str[b] != '\0'; b = b + 1) {
        while (str[b] != '\0' && check_char(str[b]) == 1)
            b = b + 1;
        if (check_char(str[b]) == 0)
            a = a + 1;
        while (str[b] != '\0' && check_char(str[b]) == 0)
            b = b + 1;
    }
    return (a);
}

char *alloc_line(int a)
{
    char *str = malloc(sizeof(char) * (a + 1));

    if (!str)
        return (NULL);
    for (int b = 0; b <= a; b = b + 1)
        str[b] = '\0';
    return (str);
}

int my_wordlen(char const *str, int a)
{
    int len = 0;

    for (int b = a; str[b] != '\0' && check_char(str[b]) == 0; b = b + 1)
        len = len + 1;
    return (len);
}

char **my_str_to_word_array(char const *str)
{
    char **tab = tab = malloc(sizeof(char *) * (nb_word(str) + 1));
    int b = 0;

    if (str == NULL)
        return (NULL);
    for (int d = 0; str[d] != '\0'; b = b + 1) {
        for ( ; str[d] != '\0' && check_char(str[d]) == 1; d = d + 1);
        tab[b] = alloc_line(my_wordlen(str, d));
        if (str[d] == '\0' || !tab[b]) {
            tab[b] = NULL;
            return (tab);
        }
        for (int c = 0; str[d] != '\0' && check_char(str[d]) == 0; d = d + 1) {
            tab[b][c] = str[d];
            c = c + 1;
        }
    }
    tab[b] = NULL;
    return (tab);
}
