/*
** EPITECH PROJECT, 2018
** my_str_to_word_array.c
** File description:
** my_str_to_word_array
*/

#include <stdlib.h>
#include "lib.h"

int nb_line(char const *str, char c)
{
    int max = my_strlen(str) - 1;
    int a = 0;
    int nb = 0;

    for (; str[a]; a = a + 1) {
        if (str[a] == c && str[a + 1] != c && a != max)
            nb = nb + 1;
    }
    if (nb == 0)
        return (1);
    return (nb + 1);
}

char **alloc_parser(char const *str, char c)
{
    int line = nb_line(str, c);
    int nb = 0;
    char **dest = malloc(sizeof(char *) * (line + 1));

    line = 0;
    for (int a = 0; str[a];) {
        for (; str[a] && str[a] == c; a = a + 1);
        for (; str[a] && str[a] != c; a = a + 1)
            nb = nb + 1;
        dest[line] = my_alloc(nb);
        line = line + 1;
        nb = 0;
    }
    return (dest);
}

char **my_str_to_word_array(char const *str, char c)
{
    char **dest = alloc_parser(str, c);
    int y = 0;

    for (int a = 0; str[a]; y = y + 1) {
        for (; str[a] && str[a] == c; a = a + 1);
        for (int x = 0; str[a] && str[a] != c; a = a + 1) {
            dest[y][x] = str[a];
            x = x + 1;
        }
        for (; str[a] && str[a] == c; a = a + 1);
    }
    dest[y] = NULL;
    return (dest);
}