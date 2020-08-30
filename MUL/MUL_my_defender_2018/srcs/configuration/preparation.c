/*
** EPITECH PROJECT, 2019
** prepa
** File description:
** prepa
*/

#include <stdlib.h>
#include "../include/defender.h"
#include "../include/my.h"

int create_seed(game_t *gt)
{
    int seed = 0;

    gt->timer.main_time = sfClock_getElapsedTime(gt->timer.main_clock);
    seed = gt->timer.main_time.microseconds;
    if (seed < 0)
        seed *= -1;
    return (seed);
}

void fill_map_with_empty(window_t *win)
{
    for (int i = 0; i <= 7 ; i++) {
        for (int j = 0; j <= 13; j++)
            win->position_map[i][j] = 0;
    }
}

void change_dir(int dir, int *x, int *y)
{
    if (dir == 1 && *y < 6)
        *y = *y + 1;
    else if (dir == 2 && *y > 0)
        *y = *y - 1;
    else
        *x = *x - 1;
}

void create_map(game_t *gt)
{
    int x = 12;
    int y =  0;
    int random = 0;
    int dir = 0;

    y = gt->info.spawn.y;
    while (x != 0) {
        random = rand() % 100;
        if (random <= 40 && dir != 2)
            dir = 1;
        else if (random <= 80 && dir != 1)
            dir = 2;
        else if (random <= 100 && random > 80)
            dir = 3;
        change_dir(dir, &x, &y);
        gt->win.position_map[y][x] = 3;
    }
    finish_map(&gt->win, &gt->info);
}

void prepare_map(game_t *gt)
{
    int seed = create_seed(gt);
    int obj = rand() % 7;

    srand(seed);
    fill_map_with_empty(&gt->win);
    gt->win.position_map[obj][0] = 1;
    gt->win.position_map[rand() % 7][12] = 2;
    get_spawn_obj(&gt->info.spawn, &gt->info.obj, &gt->win);
    create_map(gt);
    gt->win.position_map[obj][0] = 1;
}
