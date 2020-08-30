/*
** EPITECH PROJECT, 2018
** CPE_dante_2018
** File description:
** search_solution.c
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "solver.h"
#include "my.h"

int get_prev_coord(solver_t *solv)
{
    solv->visit = solv->visit - 1;
    solv->map[solv->y][solv->x] = BLOCKED;
    search_visited(solv, solv->visit);
    return (SUCCESS);
}

int get_new_coord(solver_t *solv)
{
    int y = solv->y;
    int x = solv->x;
    int a = y - 1;
    int b = x - 1;

    solv->visit = solv->visit + 1;
    for (int c = 0; c < 2; a += 2, b += 2, c++) {
        if (a >= 0 && a <= solv->ymax && solv->map[a][x] == EMPTY) {
            c = 2;
            solv->y = a;
        }
        else if (b >= 0 && b <= solv->xmax && solv->map[y][b] == EMPTY) {
            c = 2;
            solv->x = b;
        }
    }
    solv->map[solv->y][solv->x] = solv->visit;
    return (SUCCESS);
}

int nb_next_box(solver_t *solv)
{
    int y = solv->y;
    int x = solv->x;

    if (y > 0 && solv->map[y - 1][x] == EMPTY)
        return (SUCCESS);
    if (y < solv->ymax && solv->map[y + 1][x] == EMPTY)
        return (SUCCESS);
    if (x > 0 && solv->map[y][x - 1] == EMPTY)
        return (SUCCESS);
    if (x < solv->xmax && solv->map[y][x + 1] == EMPTY)
        return (SUCCESS);
    return (FAILURE);
}

int search_next_box(solver_t *solv)
{
    solv->map[solv->y][solv->x] = solv->visit;
    if (nb_next_box(solv) == FAILURE) {
        if (solv->y == 0 && solv->x == 0)
            return (NSOLUTION);
        else
            return (get_prev_coord(solv));
    }
    return (get_new_coord(solv));
}

int search_solution(solver_t solv)
{
    get_int_map(&solv);
    solv.visit = 1;
    solv.y = 0;
    solv.x = 0;
    while (solv.y < solv.ymax || solv.x < solv.xmax) {
        if (search_next_box(&solv) == NSOLUTION) {
            printf("no solution found\n");
            return (SUCCESS);
        }
    }
    set_solution(solv);
    show_my_tab(solv.tab);
    for (int a = 0; a <= solv.ymax; a++)
        free(solv.map[a]);
    free(solv.map);
    my_free(solv.tab);
    return (SUCCESS);
}