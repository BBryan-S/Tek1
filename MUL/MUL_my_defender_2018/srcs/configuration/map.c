/*
** EPITECH PROJECT, 2019
** map
** File description:
** map
*/

#include <stdlib.h>
#include "../include/my.h"
#include "../include/defender.h"

void finish_map(window_t *win, info_t *info)
{
    int pos = 0;

    for (; win->position_map[pos][0] != 3; pos++);
    if (pos > info->obj.y)
        for (; pos != info->obj.y; pos--)
            win->position_map[pos][0] = 3;
    else if (pos < info->obj.y)
        for (; pos != info->obj.y; pos++)
            win->position_map[pos][0] = 3;
}

void get_spawn_obj(sfVector2i *spawn, sfVector2i *obj, window_t *win)
{
    int x = 12;
    int y = 7;

    for (; y >= 0 && win->position_map[y][x] != 2; y--);
    spawn->x = x;
    spawn->y = y;
    for (y = 7, x = 0; y >= 0 && win->position_map[y][x] != 1; y--);
    obj->x = x;
    obj->y = y;
}

int **prep_mal(void)
{
    int **map;

    map = malloc(sizeof(int *) * 9);
    for (int i = 0; i < 9; i++)
        map[i] = malloc(sizeof(int) * 15);
    return (map);
}
