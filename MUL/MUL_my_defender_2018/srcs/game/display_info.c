/*
** EPITECH PROJECT, 2019
** info
** File description:
** info
*/

#include <stdlib.h>
#include "../include/my.h"
#include "../include/defender.h"

void display_money(game_t *gt)
{
    sfVector2f pos;

    pos.x = 90;
    pos.y = 0;
    sfSprite_setTextureRect(gt->image.entity_sprite, gt->image.money_rect);
    sfSprite_setPosition(gt->image.entity_sprite, pos);
    sfRenderWindow_drawSprite(gt->win.window, gt->image.entity_sprite, NULL);
    pos.x = 200;
    pos.y = 10;
    sfText_setString(gt->win.text_info, my_itoa(gt->info.money));
    sfText_setColor(gt->win.text_info, sfYellow);
    sfText_setPosition(gt->win.text_info, pos);
    sfText_setCharacterSize(gt->win.text_info, 40);
    sfRenderWindow_drawText(gt->win.window, gt->win.text_info, NULL);
}

void display_score(game_t *gt)
{
    sfVector2f pos;
    char *score = my_alloc(20);

    score = "Score : ";
    score = my_strcat(score, my_itoa(gt->info.score));
    pos.x = 1400;
    pos.y = 10;
    sfText_setString(gt->win.text_info, score);
    sfText_setColor(gt->win.text_info, sfYellow);
    sfText_setPosition(gt->win.text_info, pos);
    sfText_setCharacterSize(gt->win.text_info, 40);
    sfRenderWindow_drawText(gt->win.window, gt->win.text_info, NULL);
}

void display_life(game_t *gt)
{
    sfVector2f pos;
    char *live = my_alloc(20);

    live = "HP : ";
    live = my_strcat(live, my_itoa(gt->info.tower[0].hp));
    pos.x = 850;
    pos.y = 10;
    sfText_setString(gt->win.text_info, live);
    sfText_setColor(gt->win.text_info, sfYellow);
    sfText_setPosition(gt->win.text_info, pos);
    sfText_setCharacterSize(gt->win.text_info, 40);
    sfRenderWindow_drawText(gt->win.window, gt->win.text_info, NULL);
}

void display_level(game_t *gt)
{
    sfVector2f pos;
    char *level = my_alloc(20);

    level = "Level : ";
    level = my_strcat(level, my_itoa(gt->info.max_tour));
    pos.x = 1750;
    pos.y = 10;
    sfText_setString(gt->win.text_info, level);
    sfText_setColor(gt->win.text_info, sfYellow);
    sfText_setPosition(gt->win.text_info, pos);
    sfText_setCharacterSize(gt->win.text_info, 40);
    sfRenderWindow_drawText(gt->win.window, gt->win.text_info, NULL);
}

void display_info(game_t *gt)
{
    display_money(gt);
    display_score(gt);
    display_life(gt);
    display_level(gt);
}
