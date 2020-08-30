/*
** EPITECH PROJECT, 2019
** upgrade
** File description:
** up
*/

#include <stdlib.h>
#include "../include/my.h"
#include "../include/defender.h"

void get_upgrade_castle(game_t *gt, int hp, int prix, int lvl)
{
    int x = gt->win.clic_vect.x;
    int y = gt->win.clic_vect.y;

    if (is_inside(0, 500, gt) && gt->info.money >= prix) {
        gt->info.money -= prix;
        up_data_castle(&gt->info, lvl, hp);
        gt->image.obj_rect.left += 140;
        erase_panel(gt);
    }
}

void get_upgrade_tower(game_t *gt, int prix, int index)
{
    int x = gt->win.clic_vect.x;
    int y = gt->win.clic_vect.y;

    if (is_inside(0, 500, gt) && gt->info.money >= prix) {
        gt->info.money -= prix;
        up_data_tower(&gt->info, index);
        erase_panel(gt);
    }
}
