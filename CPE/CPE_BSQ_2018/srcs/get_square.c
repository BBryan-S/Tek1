/*
** EPITECH PROJECT, 2018
** get_square.c
** File description:
** get_square
*/

#include <stdlib.h>

int *find_biggest_nbr(int **map, int y, int nb_rows, int *params)
{
    for (int x = 0; x < nb_rows; x = x + 1) {
        if (map[y][x] > params[0]) {
            params[0] = map[y][x];
            params[1] = y;
            params[2] = x;
        }
    }
    return (params);
}

int **set_square(int **map, int nb_line, int nb_rows)
{
    int *params = malloc(sizeof(int) * (3));

    params[0] = 0;
    params[1] = 0;
    params[2] = 0;
    for (int y = 0; y < nb_line; y = y + 1)
        params = find_biggest_nbr(map, y, nb_rows, params);
    for (int y = params[1]; y > (params[1] - params[0]); y = y - 1) {
        for (int x = params[2]; x > (params[2] - params[0]); x = x - 1)
            map[y][x] = -1;
    }
    free(params);
    return (map);
}

int find_small(int nb2, int nb3, int nb4)
{
    int nbr = nb2;

    if (nbr > nb3)
        nbr = nb3;
    if (nbr > nb4)
        nbr = nb4;
    return ((nbr + 1));
}

int get_square_number(int **map, int y, int x)
{
    int nb1 = map[y][x];
    int nb2 = map[y][x - 1];
    int nb3 = map[y - 1][x];
    int nb4 = map[y - 1][x - 1];

    if (nb1 == 0 || nb2 == 0 || nb3 == 0 || nb4 == 0)
        return (map[y][x]);
    return (find_small(nb2, nb3, nb4));
}

int **get_square(int **map, int nb_line, int nb_rows)
{
    for (int y = 1; y < nb_line; y = y + 1) {
        for (int x = 1; x < nb_rows; x = x + 1) {
            map[y][x] = get_square_number(map, y, x);
        }
    }
    map = set_square(map, nb_line, nb_rows);
    return (map);
}