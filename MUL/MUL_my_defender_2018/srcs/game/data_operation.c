/*
** EPITECH PROJECT, 2019
** data
** File description:
** datra
*/

#include <stdlib.h>
#include "../include/my.h"
#include "../include/defender.h"

int get_index(game_t *gt, int x, int y)
{
    int ret = -1;

    for (int i = 0; i < 90; i++)
        if (gt->info.tower[i].x == x && gt->info.tower[i].y == y)
            ret = i;
    return (ret);
}

int get_data(game_t *gt, int x, int y, char *data)
{
    int ret = -1;

    for (int i = 0; i < 90; i++) {
        if (gt->info.tower[i].x == x && gt->info.tower[i].y == y)
            ret = gt->info.tower[i].id;
    }
    return (ret);
}

void push_data(sfVector2i pos, int id, info_t *info, game_t *gt)
{
    int i = 0;

    for (; (info->tower[i].id >= 0 && info->tower[i].id < 4) && i < 90; i++);
    info->tower[i].id = id;
    info->tower[i].x = pos.x;
    info->tower[i].y = pos.y;
    info->tower[i].level = 1;
    info->tower[i].hp = 0;
    info->tower[i].vda = 1;
    info->tower[i].b_vda = 10;
    info->tower[i].b_atq = 50;
    info->tower[i].ral = 10;
    info->tower[i].atq = 10;
    info->tower[i].rect = gt->image.tower_rect[id - 1];
}

void up_data_castle(info_t *info, int lvl, int hp)
{
    info->tower[0].level = lvl + 1;
    info->tower[0].hp = hp;
}

void up_data_tower(info_t *info, int index)
{
    info->tower[index].level += 1;
    info->tower[index].b_vda *= 2;
    info->tower[index].b_atq *= 3;
    info->tower[index].ral *= 2;
    info->tower[index].atq *= 5;
    info->tower[index].rect.left += 140;
}
