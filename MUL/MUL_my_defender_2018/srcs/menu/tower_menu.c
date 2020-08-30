/*
** EPITECH PROJECT, 2019
** menu_game
** File description:
** menu game
*/

#include <stdlib.h>
#include "../include/my.h"
#include "../include/defender.h"

void draw_panel(sfVector2f *pos, image_t *im, window_t *win)
{
    if (pos->x + 500 > 1920) {
        pos->x -= pos->x - 1420;
    }
    else if (pos->x < 0)
        pos->x += 0 - pos->x;
    if (pos->y + 150 > 1080)
        pos->y -= pos->y - 1230;
    else if (pos->y < 0)
        pos->y += 0 - pos->y;
    sfSprite_setTextureRect(im->entity_sprite, im->panel_rect);
    sfSprite_setPosition(im->entity_sprite, *pos);
    sfRenderWindow_drawSprite(win->window, im->entity_sprite, NULL);
}

int is_inside(int a, int b, game_t *gt)
{
    int x = gt->win.clic_vect.x;
    int y = gt->win.clic_vect.y;

    if (x >= gt->win.tower_vect.x + a && x < gt->win.tower_vect.x + b)
        if (y >= gt->win.tower_vect.y && y < gt->win.tower_vect.y + 160)
            return (1);
    return (0);
}

void get_tower(game_t *gt, sfVector2i pos)
{
    int x = gt->win.clic_vect.x;
    int y = gt->win.clic_vect.y;

    if (is_inside(30, 180, gt) && gt->info.money >= 100) {
        gt->win.position_map[pos.y][pos.x] = 4;
        gt->info.money -= 100;
        push_data(pos, 1, &gt->info, gt);
    } else if (is_inside(180, 310, gt) && gt->info.money >= 200) {
        gt->win.position_map[pos.y][pos.x] = 4;
        gt->info.money -= 200;
        push_data(pos, 2, &gt->info, gt);
    } else if (is_inside(320, 470, gt) && gt->info.money >= 400) {
        gt->win.position_map[pos.y][pos.x] = 4;
        gt->info.money -= 400;
        push_data(pos, 3, &gt->info, gt);
    } else
        return;
    erase_panel(gt);
    play_effect(gt, BUILD);
}

void panel_tower(game_t *gt, int x, int y)
{
    int is_selected = 0;
    sfVector2i pos;

    pos.x = x;
    pos.y = y;
    gt->win.tower_vect.x = x * 140 + 140;
    gt->win.tower_vect.y = (y * 140 - 80);
    if (gt->info.is_panel == 1) {
        draw_panel(&gt->win.tower_vect, &gt->image, &gt->win);
        sfSprite_setTextureRect(gt->image.entity_sprite,
                                gt->image.tower_panel_rect);
        sfSprite_setPosition(gt->image.entity_sprite, gt->win.tower_vect);
        sfRenderWindow_drawSprite(gt->win.window,
        gt->image.entity_sprite, NULL);
        get_tower(gt, pos);
    }
}
