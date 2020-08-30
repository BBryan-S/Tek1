/*
** EPITECH PROJECT, 2019
** panel
** File description:
** panel
*/

#include <stdlib.h>
#include "../include/my.h"
#include "../include/defender.h"

void parse_element(game_t *gt, int x, int y)
{
    if (x == -1)
        x = 0;
    if (y == -1)
        y = 0;
    switch (gt->win.position_map[y][x]) {
    case 0:
        panel_tower(gt, x, y);
        break;
    case 1:
        upgrade_castle(gt, x, y);
        break;
    case 4:
        upgrade_tower(gt, x, y);
        break;
    }
}

void display_panel(game_t *gt)
{
    if (gt->info.panel_display == 0) {
        gt->info.panel_pos.x = gt->win.clic_vect.x / 140;
        gt->info.panel_pos.y = gt->win.clic_vect.y / 140;
    }
    parse_element(gt, gt->info.panel_pos.x, gt->info.panel_pos.y);
}
