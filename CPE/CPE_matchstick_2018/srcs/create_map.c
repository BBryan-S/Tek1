/*
** EPITECH PROJECT, 2018
** CPE_matchstick_bootstrap_2018
** File description:
** create_map.c
*/

#include <stdlib.h>
#include <stdio.h>
#include "lib.h"

void first_end_line(char *str, int nb_line)
{
    int len = nb_line * 2;

    for (int a = 0; a <= len; a = a + 1)
        str[a] = '*';
}

void filling_line(char *str, int y, int nb_line)
{
    int len = nb_line * 2;

    for (int a = 0; a <= len; a = a + 1) {
        if (a == 0 || a == len)
            str[a] = '*';
        else if (a >= (nb_line - y + 1) && a <= (nb_line + y - 1))
            str[a] = '|';
        else
            str[a] = ' ';
    }
}

void filling_map(char **map, int nb_line)
{
    for (int a = 0; a <= nb_line + 1; a = a + 1) {
        if (a == 0 || a == (nb_line + 1))
            first_end_line(map[a], nb_line);
        else
            filling_line(map[a], a, nb_line);
    }
}

char **create_map(int nb_line)
{
    char **map;

    if (nb_line < 2 || nb_line > 99) {
        my_putstr("Bad Size\n");
        return (NULL);
    }
    map = malloc(sizeof(char *) * (nb_line + 3));
    if (!map)
        return (NULL);
    for (int a = 0; a < (nb_line + 2); a = a + 1) {
        map[a] = my_alloc((nb_line * 2) + 2);
        if (!map[a])
            return (NULL);
    }
    map[nb_line + 2] = NULL;
    filling_map(map, nb_line);
    return (map);
}