/*
** EPITECH PROJECT, 2018
** CPE_dante_2018
** File description:
** tool.c
*/

#include <stdlib.h>
#include "my.h"
#include "solver.h"

void show_my_tab(char **map)
{
    int a = 0;

    for (; map[a]; a++) {
        my_putstr(map[a]);
        if (map[a + 1])
            my_putchar('\n');
    }
}

void my_free(char **tab)
{
    for (int a = 0; tab[a]; a++)
        free(tab[a]);
    free(tab);
}

void search_visited(solver_t *solv, int visit)
{
    int y = solv->y;
    int x = solv->x;
    int a = y - 1;
    int b = x - 1;

    for (int c = 0; c < 2; a += 2, b += 2, c++) {
        if (a >= 0 && a <= solv->ymax && solv->map[a][x] == visit) {
            c = 2;
            solv->y = a;
        }
        if (b >= 0 && b <= solv->xmax && solv->map[y][b] == visit) {
            c = 2;
            solv->x = b;
        }
    }
}

void set_solution(solver_t solv)
{
    int visit = 2;

    solv.y = 0;
    solv.x = 0;
    solv.tab[solv.y][solv.x] = 'o';
    for (; solv.y < solv.ymax || solv.x < solv.xmax; visit++) {
        search_visited(&solv, visit);
        solv.tab[solv.y][solv.x] = 'o';
    }
}