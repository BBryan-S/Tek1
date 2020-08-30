/*
** EPITECH PROJECT, 2019
** defender
** File description:
** attack
*/

#include <stdlib.h>
#include "../include/my.h"
#include "../include/defender.h"

int get_bonus(game_t *gt, int index, int *b_vda)
{
    int attack = gt->info.tower[index].atq;
    int b_atq = 0;
    int x = gt->info.tower[index].x;
    int y = gt->info.tower[index].y;
    int b_x = 0;
    int b_y = 0;

    for (int i = 0; i < 90; i++) {
        if (gt->info.tower[i].id == 3) {
            b_x = gt->info.tower[i].x;
            b_y = gt->info.tower[i].y;
        }
        if (gt->info.tower[i].id == 3 &&
            (b_x == x + 1 || b_x == x - 1 || b_x == x) &&
            (b_y == y + 1 || b_y == y - 1 || b_y == y)) {
            b_atq += gt->info.tower[i].b_atq;
            *b_vda = *b_vda + gt->info.tower[i].b_vda;
        }
    }
    return (attack + (attack * b_atq / 100));
}

int is_in_range(game_t *gt, int index, int m)
{
    int x = gt->info.tower[index].x;
    int y = gt->info.tower[index].y;
    int mx = gt->info.enemi[m].pos.x;
    int my = gt->info.enemi[m].pos.y;

    if (gt->info.enemi[m].is_spawn == 1 && gt->info.enemi[m].hp > 0 &&
        (mx == x + 1 || mx == x - 1 || mx == x) &&
        (my == y + 1 || my == y - 1 || my == y))
        return (1);
    return (0);
}

void set_dmg(game_t *gt, int index, int attack, int b_vda)
{
    for (int i = 0; i < 300; i++) {
        if ((gt->info.tower[index].s_atq >= 1.0 - (1 * b_vda / 100)) &&
            is_in_range(gt, index, i) == 1) {
            sfClock_restart(gt->info.tower[index].attack);
            gt->info.enemi[i].hp -= attack;
            play_effect(gt, BOW);
        }
    }
}

void ral_enemi(game_t *gt, int index, int vda)
{
    int p_speed = 0;

    for (int i = 0; i < 300; i++) {
        p_speed = gt->info.enemi[i].speed;
        if ((gt->info.tower[index].s_atq >= 1.0 - (1 * vda / 100)) &&
            is_in_range(gt, index, i) == 1) {
            sfClock_restart(gt->info.tower[index].attack);
            gt->info.enemi[i].speed -= (gt->info.enemi[i].speed *
                                        gt->info.tower[index].ral / 100);
            play_effect(gt, RAL);
        }
        else
            gt->info.enemi[i].speed = p_speed;
    }
}

void attack_monster(game_t *gt)
{
    int attack = 0;
    int b_vda;

    if (gt->info.is_pause == 1)
        return;
    for (int i = 0; i < 90; i++) {
        gt->info.tower[i].time_atq =
            sfClock_getElapsedTime(gt->info.tower[i].attack);
        gt->info.tower[i].s_atq =
            gt->info.tower[i].time_atq.microseconds / 1000000.0;
        if (gt->info.tower[i].id == 1) {
            b_vda = 0;
            attack = get_bonus(gt, i, &b_vda);
            set_dmg(gt, i, attack, b_vda);
        } else if (gt->info.tower[i].id == 2) {
            b_vda = 0;
            attack = get_bonus(gt, i, &b_vda);
            ral_enemi(gt, i, b_vda);
        }
    }
}
