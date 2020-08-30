/*
** EPITECH PROJECT, 2018
** PSU_tetris_2018
** File description:
** tool.c
*/

#include <stdlib.h>
#include "lib.h"

void my_free(char **tab)
{
    for (int a = 0; tab[a]; a++)
        free(tab[a]);
    free(tab);
}

int my_compare_filename(char *str, char *compare, int pos)
{
    int a = pos;
    int b = 0;

    for (; str[a] && compare[b]; b++, a++) {
        if (str[a] != compare[b])
            return (-1);
    }
    if (compare[b])
        return (-1);
    return (0);
}

int check_file(char *str)
{
    int a = 0;

    for (; str[a]; a++) {
        for (; str[a] && str[a] != '.'; a++);
        if (!str[a])
            return (-1);
        if (my_compare_filename(str, ".tetrimino", a) == 0)
            return (0);
    }
    return (-1);
}

char *complete_fname(char *str)
{
    char *dest = my_alloc(my_strlen(str) + 11);

    dest = my_strcat(dest, "tetriminos/");
    dest = my_strcat(dest, str);
    return (dest);
}