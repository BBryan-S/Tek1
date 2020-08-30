/*
** EPITECH PROJECT, 2019
** display
** File description:
** displ
*/

#include <stdlib.h>
#include "../include/my.h"
#include "../include/defender.h"

void put_path(image_t *im, int x, int y, window_t *win)
{
    sfVector2f pos;

    pos.x = x * 140;
    pos.y = y * 140;
    sfSprite_setTextureRect(im->entity_sprite, im->chemin_rect);
    sfSprite_setPosition(im->entity_sprite, pos);
    sfRenderWindow_drawSprite(win->window, im->entity_sprite, NULL);
}

void put_obj(image_t *im, int x, int y, window_t *win)
{
    sfVector2f pos;

    pos.x = x * 140;
    pos.y = y * 140;
    sfSprite_setTextureRect(im->entity_sprite, im->obj_rect);
    sfSprite_setPosition(im->entity_sprite, pos);
    sfRenderWindow_drawSprite(win->window, im->entity_sprite, NULL);
}

void put_spawn(image_t *im, int x, int y, window_t *win)
{
    sfVector2f pos;

    pos.x = x * 140;
    pos.y = y * 140;
    sfSprite_setTextureRect(im->entity_sprite, im->spawn_rect);
    sfSprite_setPosition(im->entity_sprite, pos);
    sfRenderWindow_drawSprite(win->window, im->entity_sprite, NULL);
}

void parse_map(int x, int y, game_t *gt)
{
    int info = 0;

    info = gt->win.position_map[y][x];
    switch (info) {
    case 1:
        put_obj(&gt->image, x, y, &gt->win);
        break;
    case 2:
        put_spawn(&gt->image, x, y, &gt->win);
        break;
    case 3:
        put_path(&gt->image, x, y, &gt->win);
        break;
    case 4:
        put_tower(&gt->image, x, y, gt);
        break;
    default:
        break;
    }
}

void put_map(game_t *gt)
{
    for (int y = 0; y < 7; y++)
        for (int x = 0; x < 13; x++)
            parse_map(x, y, gt);
}
