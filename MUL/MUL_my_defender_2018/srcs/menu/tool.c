/*
** EPITECH PROJECT, 2019
** tool
** File description:
** tool
*/

#include <stdlib.h>
#include "../include/my.h"
#include "../include/defender.h"

void erase_mouse(game_t *gt)
{
    gt->win.clic_vect.x = 0;
    gt->win.clic_vect.y = 0;
}

void erase_panel(game_t *gt)
{
    gt->info.is_panel = 0;
    gt->info.panel_display = 0;
    gt->win.tower_vect.x = -1;
    gt->win.tower_vect.y = -1;
    gt->win.clic_vect.x = -1;
    gt->win.clic_vect.y = -1;
}

int get_color(game_t *game, sfVector2f pos)
{
    sfVector2i mouse = game->win.mouse_vect;
    sfVector2i clic = game->win.clic_vect;

    if (pos.x < clic.x && pos.x + 150 >= clic.x && pos.y < clic.y &&
        pos.y + 50 >= clic.y) {
        play_effect(game, M_CLIC);
        return (0);
    }
    else if (pos.x < mouse.x && pos.x + 150 >= mouse.x && pos.y < mouse.y &&
        pos.y + 50 >= mouse.y) {
        return (1);
    }
    return (2);
}

void change_again(int a, game_t *gt)
{
    if (a == 8)
        if (gt->audio.effet_enable == 0)
            gt->audio.effet_enable = 1;
        else
            gt->audio.effet_enable = 0;
    else if (a == 9)
        if (gt->info.money == 300)
            gt->info.money = 3000;
        else if (gt->info.money == 3000)
            gt->info.money = 1000000;
        else
            gt->info.money = 300;
    if (a == 10) {
        gt->win.select_menu = 10;
        erase_mouse(gt);
        gt->win.menu_degrees = 0;
    }
}

void change_option(int a, game_t *gt)
{
    if (a == 5) {
        if (gt->win.freq == 30)
            gt->win.freq = 60;
        else
            gt->win.freq = 30;
        sfRenderWindow_setFramerateLimit(gt->win.window, gt->win.freq);
    } else if (a == 6) {
        if (gt->info.difficulty == 1)
            gt->info.difficulty = 2;
        else
            gt->info.difficulty = 1;
    } else if (a == 7) {
        if (gt->audio.music_enable == 0)
            gt->audio.music_enable = 1;
        else
            gt->audio.music_enable = 0;
    } else
        change_again(a, gt);
    gt->win.select_option = -1;
    erase_mouse(gt);
}
