/*
** EPITECH PROJECT, 2019
** dante
** File description:
** tools
*/

#include "../include/my.h"
#include "../include/generator.h"
#include <stdlib.h>

void check_cell(gen_t *gen, int y, int x)
{
    if (gen->map[y][x] == FREE) {
        if (gen->maze_status == PERFECT)
            gen->map[y][x] = WALL;
        else
            gen->map[y][x] = PATH;
    }
}

void fill_empty(gen_t *gen)
{
    for (int y = 0; y < gen->y; y++)
        for (int x = 0; x < gen->x; x++)
            check_cell(gen, y, x);
}

void set_cell(gen_t *gen, int i, int j)
{
    if (gen->map[i][j] == PATH) {
        if (size_ok(j + 1, i, gen) && rand() % 100 > 30 &&
            gen->map[i][j + 1] == FREE)
            gen->map[i][j + 1] = WALL;
        if (size_ok(j - 1, i, gen) && rand() % 100 > 30 &&
            gen->map[i][j - 1] == FREE)
            gen->map[i][j - 1] = WALL;
        if (size_ok(j, i + 1, gen) && rand() % 100 > 30 &&
            gen->map[i + 1][j] == FREE)
            gen->map[i + 1][j] = WALL;
        if (size_ok(j, i - 1, gen) && rand() % 100 > 30 &&
            gen->map[i - 1][j] == FREE)
            gen->map[i - 1][j] = WALL;
    }
}

void set_wall(gen_t *gen)
{
    for (int i = 0; i < gen->y; i++) {
        for (int j = 0; j < gen->x; j++) {
            set_cell(gen, i, j);
        }
    }
}
