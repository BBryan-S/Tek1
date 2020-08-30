/*
** EPITECH PROJECT, 2019
** menu
** File description:
** menu
*/

#include <stdlib.h>
#include "../include/my.h"
#include "../include/defender.h"

void switch_panel(info_t *info, window_t win, game_t *gt)
{
    int lim_x = win.tower_vect.x;
    int lim_y = win.tower_vect.y;
    int clic_x = win.clic_vect.x;
    int clic_y = win.clic_vect.y;

    if (info->is_panel == 0) {
        info->panel_display = 1;
        info->is_panel = 1;
    }
    else if ((clic_x < lim_x || clic_x > lim_x + 500) || (clic_y < lim_y ||
    clic_y > lim_y + 160)) {
        info->panel_display = 0;
        info->is_panel = 0;
        win.clic_vect.x = 0;
        win.clic_vect.y = 0;
        win.tower_vect.x = 0;
        win.tower_vect.y = 0;
    }
}

void menu_event(game_t *game)
{
    if (game->win.event.type == sfEvtClosed)
        sfRenderWindow_close(game->win.window);
    if (game->win.event.type == sfEvtMouseButtonPressed) {
        game->win.clic_vect = sfMouse_getPositionRenderWindow(game->win.window);
        play_effect(game, G_CLIC);
        if (game->info.is_pause == 0)
            switch_panel(&game->info, game->win, game);
    }
    game->win.mouse_vect = sfMouse_getPositionRenderWindow(game->win.window);

}

void menu_aide(game_t *gt)
{
    sfVector2f pos;

    sfRenderWindow_drawSprite(gt->win.window, gt->image.help_sprite, NULL);
    pos.x = 100;
    pos.y = 10;
    if (get_color(gt, pos) == 1)
        sfText_setColor(gt->win.text_menu, sfRed);
    else if (get_color(gt, pos) == 0)
        gt->win.select_menu = -1;
    sfText_setString(gt->win.text_menu, "Retour");
    sfText_setPosition(gt->win.text_menu, pos);
    sfRenderWindow_drawText(gt->win.window, gt->win.text_menu, NULL);
}

int launch_menu(game_t *gt)
{
    gt->win.menu_degrees = 0;
    while (sfRenderWindow_isOpen(gt->win.window)) {
        sfRenderWindow_drawSprite(gt->win.window, gt->image.menu_sprite, NULL);
        switch (display_menu_start(gt)) {
        case 0:
            return (0);
        case 4:
            return (-1);
            break;
        default:
            next_menu(gt);
            break;
        }
        while (sfRenderWindow_pollEvent(gt->win.window, &gt->win.event))
            menu_event(gt);
        sfRenderWindow_display(gt->win.window);
    }
}
