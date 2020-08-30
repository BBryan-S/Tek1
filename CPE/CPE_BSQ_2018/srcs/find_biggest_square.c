/*
** EPITECH PROJECT, 2018
** find_biggest_square.c
** File description:
** find_biggest_square
*/

#include <stdlib.h>
#include <unistd.h>
#include "../include/my.h"
#include "../include/bsq.h"
#include <stdio.h>

void my_free_map(int **map, int nb_line)
{
    for (int a = 0; a <= nb_line; a = a + 1)
        free(map[a]);
    free(map);
}

int get_map_nbr(char c)
{
    if (c == '.')
        return (1);
    else
        return (0);
}

char get_my_char(int nb)
{
    if (nb == 0)
        return ('o');
    else if (nb == -1)
        return ('x');
    else
        return ('.');
}

char *tab_to_str(int **map, char *bsq)
{
    int x = 0;
    int y = 0;

    for (int a = 0; bsq[a]; a = a + 1) {
        if (bsq[a] == '\n') {
            y = y + 1;
            x = 0;
        }
        else {
            bsq[a] = get_my_char(map[y][x]);
            x = x + 1;
        }
    }
    return (bsq);
}

void find_biggest_square(char *bsq, int nb_line, int nb_rows, int len)
{
    int **map;
    int x = 0;
    int y = 0;

    map = malloc(sizeof(int *) * (nb_line + 1));
    map[y] = malloc(sizeof(int) * (nb_rows + 2));
    for (int a = 0; bsq[a]; a = a + 1) {
        if (bsq[a] == '\n') {
            y = y + 1;
            x = 0;
            map[y] = malloc(sizeof(int) * (nb_rows + 2));
        } else {
            map[y][x] = get_map_nbr(bsq[a]);
            x = x + 1;
        }
    }
    map = get_square(map, nb_line, nb_rows);
    write(1, tab_to_str(map, bsq), len);
    my_free_map(map, nb_line);
    free(bsq);
}
