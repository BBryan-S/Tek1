/*
** EPITECH PROJECT, 2019
** menu_game
** File description:
** menu game
*/

#include <stdlib.h>
#include "../include/my.h"
#include "../include/defender.h"

void put_text_castle(game_t *gt, int n_hp, int prix, int lvl)
{
    char *str = my_alloc(100);

    gt->win.tower_vect.y += 50;
    gt->win.tower_vect.x += 50;
    str = "    UPGRADE :\n\nNiveau actuel : ";
    str = my_strcat(str, my_itoa(lvl));
    str = my_strcat(str, "\nProchain niveau : ");
    str = my_strcat(str, my_itoa(n_hp));
    str = my_strcat(str, " Hp\n\n\n       ");
    str = my_strcat(str, my_itoa(prix));
    sfText_setString(gt->win.text_menu, str);
    sfText_setColor(gt->win.text_menu, sfYellow);
    sfText_setPosition(gt->win.text_menu, gt->win.tower_vect);
    sfText_setCharacterSize(gt->win.text_menu, 25);
    sfRenderWindow_drawText(gt->win.window, gt->win.text_menu, NULL);
    sfSprite_setTextureRect(gt->image.entity_sprite, gt->image.money_rect);
    gt->win.tower_vect.y += 80;
    sfSprite_setPosition(gt->image.entity_sprite, gt->win.tower_vect);
    sfRenderWindow_drawSprite(gt->win.window, gt->image.entity_sprite, NULL);
}

void display_text_castle(game_t *gt, int lvl, int hp)
{
    int n_hp = hp + 2 * (lvl + 1) * 300;
    int prix;

    if (lvl == 2)
        prix = 5000;
    else if (lvl == 3)
        prix = 10000;
    else
        prix = 100000;
    if (lvl == 1)
        prix = 1000;
    put_text_castle(gt, n_hp, prix, lvl);
    get_upgrade_castle(gt, n_hp, prix, lvl);
}

void display_max_level(game_t *gt)
{
    char *str = "MAX LEVEL !";

    gt->win.tower_vect.x += 100;
    gt->win.tower_vect.y += 80;
    sfText_setString(gt->win.text_menu, str);
    sfText_setColor(gt->win.text_menu, sfYellow);
    sfText_setPosition(gt->win.text_menu, gt->win.tower_vect);
    sfText_setCharacterSize(gt->win.text_menu, 40);
    sfRenderWindow_drawText(gt->win.window, gt->win.text_menu, NULL);
}

void display_information(game_t *gt)
{
    int hp = gt->info.tower[0].hp;
    int level = gt->info.tower[0].level;

    if (level < 5) {
        display_text_castle(gt, level, hp);
    }
    else
        display_max_level(gt);
}

void upgrade_castle(game_t *gt, int x, int y)
{
    gt->win.tower_vect.x = x * 140 + 140;
    gt->win.tower_vect.y = (y * 140 - 80);
    if (gt->info.is_panel == 1) {
        draw_panel(&gt->win.tower_vect, &gt->image, &gt->win);
        display_information(gt);
    }
}
