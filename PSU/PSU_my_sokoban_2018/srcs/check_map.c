/*
** EPITECH PROJECT, 2018
** check_map.c
** File description:
** check_map
*/

#include "../include/lib.h"

void check_map_gameplay(char c, int *nb_box, int *nb_players, int *nb_storage)
{
    if (c == 'P')
        *nb_players = *nb_players + 1;
    if (c == 'O')
        *nb_storage = *nb_storage + 1;
    if (c == 'X')
        *nb_box = *nb_box + 1;
}

int check_map_char(char c)
{
    if (c == 'P' || c == 'X' || c == 'O')
        return (0);
    else if (c == ' ' || c == '#')
        return (0);
    else
        return (84);
}

int bad_char(char *str)
{
    for (int a = 0; str[a]; a = a + 1) {
        if (check_map_char(str[a]) == 84)
            return (84);
    }
    return (0);
}

int check_map(char **map)
{
    int nb_box = 0;
    int nb_players = 0;
    int nb_storage = 0;

    for (int a = 0; map[a]; a = a + 1)
        if (bad_char(map[a]) == 84)
            return (84);
    for (int a = 0; map[a]; a = a + 1) {
        for (int b = 0; map[a][b]; b = b + 1)
            check_map_gameplay(map[a][b], &nb_box, &nb_players, &nb_storage);
    }
    if (nb_players != 1)
        return (84);
    if (nb_box == 0 || nb_box < nb_storage || nb_storage == 0)
        return (84);
    return (0);
}