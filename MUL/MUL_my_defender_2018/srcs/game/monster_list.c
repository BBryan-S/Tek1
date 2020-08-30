/*
** EPITECH PROJECT, 2019
** defender
** File description:
** array monster
*/

#include <stdlib.h>
#include "../include/my.h"
#include "../include/defender.h"

void set_info_enemi(enemi_t *en, image_t *im)
{
    en->hp = en->id * en->level * 80;
    en->rew = 10 * en->id * en->level;
    en->atq = 10 * en->id * en->level;
    en->rect = im->enemi_rect[en->id - 1];
    en->is_spawn = 0;
    switch (en->id) {
    case 2:
        en->speed = 200;
        break;
    case 3:
        en->speed = 150;
        break;
    case 5:
        en->speed = 60;
        break;
    default:
        en->speed = 100;
        break;
    }
}

void fill_array(game_t *gt)
{
    for (int i = 0; i <= 59; i++)
        gt->info.enemi[i].id = 1;
    for (int i = 60; i <= 119; i++)
        gt->info.enemi[i].id = 2;
    for (int i = 120; i <= 179; i++)
        gt->info.enemi[i].id = 3;
    for (int i = 180; i <= 239; i++)
        gt->info.enemi[i].id = 4;
    for (int i = 240; i < 300; i++)
        gt->info.enemi[i].id = 4;
    for (int i = 0; i < 300; i++)
        set_info_enemi(&gt->info.enemi[i], &gt->image);
}

void clear_enemi(game_t *gt)
{
    for (int i = 0; i < 300; i++) {
        gt->info.enemi[i].fpos.x = -200;
        gt->info.enemi[i].fpos.y = -200;
        gt->info.enemi[i].state = -1;
        set_info_enemi(&gt->info.enemi[i], &gt->image);
    }
}

void put_hp(game_t *gt, int index)
{
    sfVector2f pos;

    pos.x = gt->info.enemi[index].fpos.x + 60;
    pos.y = gt->info.enemi[index].fpos.y + 30;
    if (gt->info.enemi[index].hp <= 0)
        return;
    sfText_setString(gt->win.text_info, my_itoa(gt->info.enemi[index].hp));
    sfText_setColor(gt->win.text_info, sfYellow);
    sfText_setPosition(gt->win.text_info, pos);
    sfText_setCharacterSize(gt->win.text_info, 15);
    sfRenderWindow_drawText(gt->win.window, gt->win.text_info, NULL);
}
