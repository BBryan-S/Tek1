/*
** EPITECH PROJECT, 2019
** tower
** File description:
** tower
*/

#include <stdlib.h>
#include "../include/my.h"
#include "../include/defender.h"

void put_tower(image_t *im, int x, int y, game_t *gt)
{
    int id = get_index(gt, x, y);
    sfVector2f pos;

    pos.x = x * 140;
    pos.y = y * 140;
    if (id == -1)
        return;
    sfSprite_setTextureRect(im->entity_sprite, gt->info.tower[id].rect);
    sfSprite_setPosition(im->entity_sprite, pos);
    sfRenderWindow_drawSprite(gt->win.window, im->entity_sprite, NULL);
}
