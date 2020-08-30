/*
** EPITECH PROJECT, 2019
** defender
** File description:
** display monster
*/

#include <stdlib.h>
#include "../include/my.h"
#include "../include/defender.h"

int get_dir(info_t *info, int index, int **map)
{
    int x = info->enemi[index].pos.x;
    int y = info->enemi[index].pos.y;
    int dir = - 1;
    int pdir = info->enemi[index].p_dir;

    if (y < 8 && map[y + 1][x] == 3 && pdir != 2)
        dir = 1;
    else if (y > 0 && map[y - 1][x] == 3 && pdir != 1)
        dir = 2;
    else if (map[y][x - 1] == 3)
        dir = 3;
    else
        info->enemi[index].p_dir = -1;
    if ((y < 9 && map[y + 1][x] == 1) || (y > 0 && map[y - 1][x] == 1) ||
        map[y][x - 1] == 1) {
        info->enemi[index].rect.top += 140;
        info->enemi[index].state = 2;
    }
    return (dir);

}

void move_in_dir(enemi_t *en)
{
    switch (en->dir) {
    case 1:
        en->fpos.y += 3 * en->speed / 100;
        break;
    case 2:
        en->fpos.y -= 3 * en->speed / 100;
        break;
    case 3:
        en->fpos.x -= 3 * en->speed / 100;
        break;
    default :
        break;
    }
}

void move_en(info_t *info, int **map, int index, game_t *gt)
{
    if (gt->timer.mv_s < 0.025 / info->difficulty && info->is_pause == 0)
        return;
    info->enemi[index].dir = get_dir(info, index, map);
    move_in_dir(&info->enemi[index]);
    if (info->enemi[index].fpos.y / 140 >= info->enemi[index].pos.y + 1) {
        info->enemi[index].p_dir = info->enemi[index].dir;
        info->enemi[index].dir = -1;
        info->enemi[index].pos.y++;
    }
    else if (info->enemi[index].fpos.y / 140 <= info->enemi[index].pos.y - 1) {
        info->enemi[index].p_dir = info->enemi[index].dir;
        info->enemi[index].dir = -1;
        info->enemi[index].pos.y--;
    }
    if (info->enemi[index].fpos.x / 140 <= info->enemi[index].pos.x - 1) {
        info->enemi[index].dir = -1;
        info->enemi[index].pos.x--;
    }
}

void anim_monster(info_t *info, game_t *gt, int index, sfSprite *ent)
{
    if (info->enemi[index].state > 0 && info->enemi[index].state < 3) {
        info->enemi[index].rect.left += 140;
        if (info->enemi[index].rect.left > 140)
            info->enemi[index].rect.left = 0;
    }
    if (info->enemi[index].state != 3 && info->enemi[index].hp <= 0) {
        if (info->enemi[index].state == 1)
            info->enemi[index].rect.top += 140;
        info->enemi[index].rect.top += 140;
        info->enemi[index].state = 3;
        info->money += info->enemi[index].rew;
        info->score += info->enemi[index].rew;
        play_effect(gt, DIE);
    }
}

void display_monster(game_t *gt, image_t *im)
{
    prepare_timer(&gt->timer);
    for (int i = 0; i < 300; i++) {
        sfSprite_setTextureRect(im->entity_sprite, gt->info.enemi[i].rect);
        if (gt->timer.ani_s >= 0.3) {
            anim_monster(&gt->info, gt, i, gt->image.entity_sprite);
            attack_tower(gt, i);
            sfClock_restart(gt->timer.anim);
        }
        if (gt->info.enemi[i].is_spawn == 1) {
            sfSprite_setTextureRect(im->entity_sprite, gt->info.enemi[i].rect);
            sfSprite_setPosition(im->entity_sprite, gt->info.enemi[i].fpos);
            put_hp(gt, i);
            sfRenderWindow_drawSprite(gt->win.window, im->entity_sprite, NULL);
        }
        if (gt->info.enemi[i].is_spawn == 1 && gt->info.enemi[i].state == 1 &&
            gt->info.is_pause == 0)
            move_en(&gt->info, gt->win.position_map, i, gt);
    }
    if (gt->timer.mv_s >= 0.025)
        sfClock_restart(gt->timer.mvt);
}
