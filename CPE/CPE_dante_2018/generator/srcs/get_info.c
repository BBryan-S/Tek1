/*
** EPITECH PROJECT, 2018
** Visual Studio Live Share (Workspace)
** File description:
** get_info.c
*/

#include "generator.h"
#include <stdlib.h>
#include <string.h>

int get_info(int ac, char **av, gen_t *gen)
{
    if (ac < 3)
        return (ERROR);
    gen->maze_status = IMPERFECT;
    gen->x = atoi(av[1]);
    gen->y = atoi(av[2]);
    gen->maze_status = 0;
    if (gen->x < 1 || gen->y < 1 || (gen->x * gen->y) >= 90000)
        return (ERROR);
    if (ac < 4)
        return (SUCCESS);
    if (strcmp(av[3], "perfect") == SUCCESS)
        gen->maze_status = PERFECT;
    else if (strcmp(av[3], "imperfect") == SUCCESS)
        gen->maze_status = IMPERFECT;
    else
        return (ERROR);
    return (SUCCESS);
}
