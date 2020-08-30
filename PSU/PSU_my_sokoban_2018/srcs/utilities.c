/*
** EPITECH PROJECT, 2018
** utilities.c
** File description:
** utilities
*/

#include <ncurses.h>
#include <stdlib.h>
#include "../include/lib.h"

int search_char(char *str, char c)
{
    for (int a = 0; str[a]; a = a + 1) {
        if (str[a] == c)
            return (1);
    }
    return (0);
}

char **map_dup(char **map)
{
    char **dest;
    int a = 0;
    int b = 0;

    for (; map[a]; a = a + 1);
    dest = malloc(sizeof(char *) * (a + 1));
    if (!dest)
        return (NULL);
    for (; b < a; b = b + 1) {
        dest[b] = my_strdup(map[b]);
        if (!dest[b])
            return (NULL);
    }
    dest[b] = NULL;
    return (dest);
}

void print_map(char **map)
{
    for (int a = 0; map[a]; a = a + 1)
        printw("%s\n", map[a]);
}

void get_position(char **map, int *y, int *x)
{
    for (; map[*y]; *y = *y + 1) {
        for (*x = 0; map[*y][*x] && map[*y][*x] != 'P'; *x = *x + 1);
        if (map[*y][*x] == 'P')
            return;
    }
}