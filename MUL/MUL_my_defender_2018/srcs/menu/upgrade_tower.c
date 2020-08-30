/*
** EPITECH PROJECT, 2019
** menu_game
** File description:
** menu game
*/

#include <stdlib.h>
#include "../include/my.h"
#include "../include/defender.h"

char *get_description_tower(int type, int index, int prix, game_t *gt)
{
    char *str = my_alloc(100);

    str = "   UPGRADE :\n\n ";
    if (type == 1) {
        str = my_strcat(str, "Attaque :\n\n     ");
        str = my_strcat(str, my_itoa(gt->info.tower[index].atq));
        str = my_strcat(str, "  -<  ");
        str = my_strcat(str, my_itoa(gt->info.tower[index].atq * 5));
    } else if (type == 2) {
        str = my_strcat(str, "Ralentissement :\n\n    ");
        str = my_strcat(str, my_itoa(gt->info.tower[index].ral));
        str = my_strcat(str, " %  -<  ");
        str = my_strcat(str, my_itoa(gt->info.tower[index].ral * 2));
        str = my_strcat(str, " %");
    } else if (type == 3)
        str = next_description(str, index, type, gt);
    return (str);
}

void put_text_tower(game_t *gt, int prix, int type, int index)
{
    char *str = get_description_tower(type, index, prix, gt);

    gt->win.tower_vect.y += 50;
    gt->win.tower_vect.x += 50;
    str = my_strcat(str, "\n\n         ");
    str = my_strcat(str, my_itoa(prix));
    sfText_setString(gt->win.text_menu, str);
    sfText_setColor(gt->win.text_menu, sfYellow);
    sfText_setPosition(gt->win.text_menu, gt->win.tower_vect);
    sfText_setCharacterSize(gt->win.text_menu, 25);
    if (type == 3)
        sfText_setCharacterSize(gt->win.text_menu, 20);
    sfRenderWindow_drawText(gt->win.window, gt->win.text_menu, NULL);
    sfSprite_setTextureRect(gt->image.entity_sprite, gt->image.money_rect);
    gt->win.tower_vect.y += 80;
    sfSprite_setPosition(gt->image.entity_sprite, gt->win.tower_vect);
    sfRenderWindow_drawSprite(gt->win.window, gt->image.entity_sprite, NULL);
}

void display_text_tower(game_t *gt, int index)
{
    int lvl = gt->info.tower[index].level;
    int type = gt->info.tower[index].id;
    int prix;

    if (lvl == 1)
        prix = type * 500;
    else
        prix = type * 5000;
    put_text_tower(gt, prix, type, index);
    get_upgrade_tower(gt, prix, index);
}

void display_tow_up(game_t *gt, int x, int y)
{
    int index = get_index(gt, x, y);

    if (gt->info.tower[index].id < 0)
        return;
    if (gt->info.tower[index].level < 3)
        display_text_tower(gt, index);
    else
        display_max_level(gt);
}

void upgrade_tower(game_t *gt, int x, int y)
{
    gt->win.tower_vect.x = x * 140 + 140;
    gt->win.tower_vect.y = (y * 140 - 80);
    if (gt->info.is_panel == 1) {
        draw_panel(&gt->win.tower_vect, &gt->image, &gt->win);
        display_tow_up(gt, x, y);
    }
}
