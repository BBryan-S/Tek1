/*
** EPITECH PROJECT, 2018
** CPE_dante_2018
** File description:
** main.c
*/

#include <stdio.h>
#include <stdlib.h>
#include "my.h"
#include "solver.h"

int check_start_finish(char **map)
{
    int len = my_strlen(map[0]) - 1;
    int a = 0;

    if (map[0][0] == 'X')
        return (FAILURE);
    for (; map[a] && map[a + 1] != NULL; a++);
    if (map[a][len] == 'X')
        return (FAILURE);
    return (SUCCESS);
}

int main(int ac, char **av)
{
    solver_t solv;

    if (ac < 2)
        return (ERROR);
    solv.tab = get_map(av[1]);
    if (!solv.tab)
        return (ERROR);
    if (check_start_finish(solv.tab) == FAILURE)
        printf("no solution found\n");
    else
        search_solution(solv);
    return (SUCCESS);
}