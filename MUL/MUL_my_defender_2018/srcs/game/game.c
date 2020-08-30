/*
** EPITECH PROJECT, 2019
** menu
** File description:
** menu
*/

#include <stdlib.h>
#include "../include/my.h"
#include "../include/defender.h"

int take_a_break(game_t *gt)
{
    if (menu_pause(gt) == 1) {
        gt->timer.main_clock = sfClock_create();
        erase_mouse(gt);
        gt->info.is_pause = 0;
    }
    else if (menu_pause(gt) == 2) {
        gt->info.is_pause = 0;
        erase_mouse(gt);
        return (-1);
    }
    else if (menu_pause(gt) == 3) {
        erase_mouse(gt);
        gt->win.menu_degrees = 0;
        gt->win.select_menu = 5;
        if (sfMusic_getStatus(gt->audio.music) == 2)
            sfMusic_destroy(gt->audio.music);
        return (1);
    }
    return (0);
}

void game_event(game_t *gt)
{
    menu_event(gt);
    if (sfKeyboard_isKeyPressed(sfKeyEscape) && gt->info.is_pause == 0) {
        sfClock_destroy(gt->timer.main_clock);
        gt->info.is_pause = 1;
        erase_mouse(gt);
        play_effect(gt, PAUSE);
    }
}

void display_stuff(game_t *gt)
{
    put_map(gt);
    put_monster(gt);
    display_monster(gt, &gt->image);
    display_info(gt);
    display_panel(gt);
    attack_monster(gt);
}

int launch_game(game_t *gt)
{
    int end = 0;

    erase_mouse(gt);
    fill_array(gt);
    while (sfRenderWindow_isOpen(gt->win.window) && end == 0) {
        sfRenderWindow_drawSprite(gt->win.window, gt->image.bg_sprite, NULL);
        display_stuff(gt);
        while (sfRenderWindow_pollEvent(gt->win.window, &gt->win.event))
            game_event(gt);
        if (gt->info.tower[0].hp <= 0)
            return (-42);
        if (gt->info.is_pause == 1)
            end = take_a_break(gt);
        sfRenderWindow_display(gt->win.window);
    }
    return (end);
}
