/*
** EPITECH PROJECT, 2018
** CPE_matchstick_bootstrap_2018
** File description:
** main.c
*/

#include <unistd.h>
#include "lib.h"
#include "matchstick.h"

int get_map_params(char **av, int *nb_line, int *nb_matches)
{
    if (my_getnbr(av[1], nb_line) == -1)
        return (-1);
    if (my_getnbr(av[2], nb_matches) == -1)
        return (-1);
    return (0);
}

int main(int ac, char **av)
{
    char **map;
    int nb_line = 0;
    int nb_matches = 0;

    if (ac < 3)
        return (84);
    if (get_map_params(av, &nb_line, &nb_matches) == -1) {
        write(2, "Invalid input\n", 15);
        return (84);
    } else if (nb_line < 1) {
        write(2, "line should be between 1 and 100\n", 34);
        return (84);
    }
    map = create_map(nb_line);
    if (!map)
        return (84);
    return (game(map, nb_line, nb_matches));
}