/*
** EPITECH PROJECT, 2019
** dante
** File description:
** branch
*/

#include "../include/my.h"
#include "../include/generator.h"
#include <stdlib.h>

int no_path(int x, int y, gen_t *gen)
{
    int ret = 0;

    for (int i = -1; i < 2; i++) {
        if (size_ok(x, y + i, gen) && gen->map[y + i][x] == PATH)
            ret++;
        if (size_ok(x + i, y, gen) && gen->map[y][x + i] == PATH)
            ret++;
    }
    if (ret <= 1)
        return (1);
    return (0);
}

int is_empty(int *x, int *y, gen_t *gen)
{
    int s_x = *x;
    int s_y = *y;

    if (size_ok(*x, *y + 1, gen) && gen->map[*y + 1][*x] == FREE &&
        no_path(*x, *y + 1, gen))
        *y = *y + 1;
    if (size_ok(*x, *y - 1, gen) && gen->map[*y - 1][*x] == FREE &&
        no_path(*x, *y - 1, gen))
        *y = *y - 1;
    if (size_ok(*x + 1, *y, gen) && gen->map[*y][*x + 1] == FREE &&
        no_path(*x + 1, *y, gen))
        *x = *x + 1;
    if (size_ok(*x - 1, *y, gen) && gen->map[*y][*x - 1] == FREE &&
        no_path(*x - 1, *y, gen))
        *x = *x - 1;
    if (s_x == *x && s_y == *y)
        return (0);
    return (1);
}

void new_branch(gen_t *gen, int x, int y)
{
    int count = 0;

    if (gen->map[y][x] == PATH && is_empty(&x, &y, gen)) {
        for (; count < 10; count++) {
            gen->map[y][x] = PATH;
            is_empty(&x, &y, gen);
        }
    }
}

void make_branch(gen_t *gen)
{
    for (int y = 0; y < gen->y; y++)
        for (int x = 0; x < gen->x; x++)
            new_branch(gen, x, y);
}
