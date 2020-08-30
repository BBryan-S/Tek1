/*
** EPITECH PROJECT, 2019
** menu
** File description:
** menu
*/

#include <stdlib.h>
#include "../include/my.h"
#include "../include/defender.h"

int compare_select(char *str)
{
    if (my_strcmp(str, "Reprendre") == 0)
        return (1);
    else if (my_strcmp(str, "Menu") == 0)
        return (3);
    else if (my_strcmp(str, "Quitter") == 0)
        return (2);
}

void prepare_pause(window_t *win, char *str, sfVector2f pos, int col)
{
    sfColor color = sfYellow;

    if (col == 0)
        color = sfBlue;
    else if (col == 1)
        color = sfRed;
    sfText_setString(win->text_menu, str);
    sfText_setColor(win->text_menu, color);
    sfText_setPosition(win->text_menu, pos);
    sfText_setCharacterSize(win->text_menu, 40);
    if (col == 0)
        win->select_menu = compare_select(str);
}

int menu_pause(game_t *gt)
{
    sfVector2f pos;

    gt->win.select_menu = -1;
    sfRenderWindow_drawSprite(gt->win.window, gt->image.pause_sprite, NULL);
    pos.x = gt->win.width / 2 - 100;
    pos.y = gt->win.height / 2 - 100;
    prepare_pause(&gt->win, "Reprendre", pos, get_color(gt, pos));
    sfRenderWindow_drawText(gt->win.window, gt->win.text_menu, NULL);
    pos.y += 100;
    prepare_pause(&gt->win, "Menu", pos, get_color(gt, pos));
    sfRenderWindow_drawText(gt->win.window, gt->win.text_menu, NULL);
    pos.y += 100;
    prepare_pause(&gt->win, "Quitter", pos, get_color(gt, pos));
    sfRenderWindow_drawText(gt->win.window, gt->win.text_menu, NULL);
    return (gt->win.select_menu);
}
