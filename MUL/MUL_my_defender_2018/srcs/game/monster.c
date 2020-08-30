/*
** EPITECH PROJECT, 2019
** monster
** File description:
** monster
*/

#include <stdlib.h>
#include "../include/my.h"
#include "../include/defender.h"

int all_en_die(game_t *gt)
{
    int die = 1;

    for (int i = 0; i < 300; i++)
        if (gt->info.enemi[i].is_spawn == 1 && gt->info.enemi[i].hp > 0)
            die = 0;
    return (die);
}

void spawn_monster(info_t *info)
{
    int index = info->actual_monster;

    info->enemi[index].hp = info->enemi[index].id * info->enemi[index].level
        * 80 + (info->max_tour * 5);
    info->enemi[index].is_spawn = 1;
    info->enemi[index].pos = info->spawn;
    info->enemi[index].fpos.x = info->spawn.x * 140.0;
    info->enemi[index].fpos.y = info->spawn.y * 140.0;
    info->enemi[index].dir = -1;
    info->enemi[index].state = 1;
}

void level_up(int max, enemi_t *en, image_t *im)
{
    int res = 1;

    if (max % 10 == 0)
        res = max / 10;
    for (int i = 0; i < max * 6; i++)
        en[i].level = res;
    set_info_enemi(en, im);
}

void put_monster(game_t *gt)
{
    prepare_timer(&gt->timer);
    if (gt->timer.second >= 1.5 / gt->info.difficulty / gt->info.max_tour &&
        gt->info.is_pause == 0) {
        sfClock_restart(gt->timer.main_clock);
        if (gt->info.actual_monster < 299)
            gt->info.actual_monster++;
        if (gt->info.actual_monster % 6 == 0)
            gt->info.actual_tour++;
        if (gt->info.actual_tour >= gt->info.max_tour && all_en_die(gt) == 1) {
            clear_enemi(gt);
            gt->info.max_tour++;
            gt->info.actual_tour = 0;
            gt->info.actual_monster = 0;
            gt->info.score += 100;
        }
        if (gt->info.actual_tour < gt->info.max_tour)
            spawn_monster(&gt->info);
        level_up(gt->info.max_tour, gt->info.enemi, &gt->image);
    }
}
