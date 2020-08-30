/*
** EPITECH PROJECT, 2018
** Visual Studio Live Share (Workspace)
** File description:
** generator.c
*/

#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include "../include/my.h"
#include "../include/generator.h"

int size_ok(int x, int y, gen_t *gen)
{
    if (x >= gen->x || x < 0 || y >= gen->y || y < 0) {
        return (0);
    }
    return (1);
}

void get_dir (int *x, int *y, gen_t *gen)
{
    int random;
    int s_x = *x;
    int s_y = *y;

    while (s_x == *x && s_y == *y) {
        random = rand() % 2;
        if (size_ok(*x + 1, *y, gen) &&
            random == 0 && gen->map[*y][*x + 1] == FREE)
            *x = *x + 1;
        else if (size_ok(*x, *y + 1, gen) &&
                random == 1 && gen->map[*y + 1][*x] == FREE)
            *y = *y + 1;
    }
}

int make_solution(gen_t *gen)
{
    int x = 0;
    int y = 0;

    while (x != gen->x - 1 || y != gen->y - 1) {
        gen->map[y][x] = PATH;
        get_dir(&x, &y, gen);
    }
    gen->map[gen->y - 1][gen->x - 1] = PATH;
    set_wall(gen);
    return (0);
}

void generator(gen_t *gen)
{
    int count = 0;

    make_solution(gen);
    while (count < gen->x + gen->y) {
        make_branch(gen);
        set_wall(gen);
        count++;
    }
    fill_empty(gen);
}
