/*
** EPITECH PROJECT, 2019
** entity
** File description:
** entity
*/

#include <stdlib.h>
#include "../include/my.h"
#include "../include/defender.h"

void prepare_enemi(info_t *info)
{
    info->enemi = malloc(sizeof(enemi_t) * 320);
    for (int i = 0; i < 300; i++) {
        info->enemi[i].id = -1;
        info->enemi[i].level = 1;
        info->enemi[i].is_spawn = 0;
        info->enemi[i].p_dir = -1;
        info->enemi[i].fpos.x = -150;
        info->enemi[i].fpos.y = -150;
    }
}

void is_castle(int y, int x, int **map, tower_t *tower)
{
    if (map[y][x] == 1) {
        tower->pos.x = x;
        tower->pos.y = y;
    }
}

void prepare_tower(info_t *info, window_t *win)
{
    info->tower = malloc(sizeof(tower_t) * 90);
    for (int i = 0; i < 90; i++) {
        info->tower[i].id = -1;
        info->tower[i].x = -1;
        info->tower[i].y = -1;
        info->tower[i].attack = sfClock_create();
    }
    info->tower[0].id = 0;
    info->tower[0].hp = 100;
    info->tower[0].level = 1;
    for (int y = 0; y < 7; y++)
        for (int x = 0; x < 13; x++)
            is_castle(y, x, win->position_map, &info->tower[0]);
}

void prepare_entity(game_t *gt)
{
    prepare_enemi(&gt->info);
    prepare_tower(&gt->info, &gt->win);
}
