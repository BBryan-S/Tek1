/*
** EPITECH PROJECT, 2018
** CPE_matchstick_bootstrap_2018
** File description:
** get_params.c
*/

#include <stdlib.h>
#include "lib.h"
#include "get_next_line.h"

int check_line(char *str, int matches)
{
    int nb = 0;

    for (int a = 0; str[a]; a = a + 1) {
        if (str[a] == '|')
            nb = nb + 1;
    }
    if (matches > nb)
        return (-1);
    return (0);
}

int error_matches(char **map, int matches, int nb_matches, int line)
{
    if (matches < 1 || matches > nb_matches) {
        if (matches < 1) {
            my_putstr("Error: you have to remove ");
            my_putstr("at least one match\n");
        } else {
            my_putstr("Error: you cannot remove more than ");
            my_put_nbr(nb_matches);
            my_putstr(" matches per turn\n");
        }
        matches = -1;
    }
    if (check_line(map[line], matches) == -1) {
        matches = -1;
        my_putstr("Error: not enough matches on this line\n");
    }
    return (matches);
}

int get_matches(char **map, int line, int nb_matches)
{
    int matches;
    char *str;

    my_putstr("Matches: ");
    str = get_next_line(0);
    if (!str)
        return (-2);
    if (my_getnbr(str, &matches) == -1) {
        my_putstr("Error: invalid input ");
        my_putstr("(positive number expected)\n");
        return (-1);
    }
    free(str);
    matches = error_matches(map, matches, nb_matches, line);
    return (matches);
}

int get_line(int nb_line)
{
    int line = -1;
    char *str;

    while (line == -1) {
        my_putstr("Line: ");
        str = get_next_line(0);
        if (!str)
            return (-2);
        if (my_getnbr(str, &line) == -1) {
            my_putstr("Error: invalid input ");
            my_putstr("(positive number expected)\n");
        } else if (line == 0 || line > nb_line) {
            line = -1;
            my_putstr("Error: this line is out of range\n");
        }
        free(str);
    }
    return (line);
}