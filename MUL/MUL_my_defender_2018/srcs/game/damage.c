/*
** EPITECH PROJECT, 2019
** defender
** File description:
** damage
*/

#include <stdlib.h>
#include "../include/my.h"
#include "../include/defender.h"

void attack_tower(game_t *gt, int index)
{
    if (gt->info.enemi[index].state == 2)
        gt->info.tower[0].hp -= gt->info.enemi[index].atq / 3;
}
