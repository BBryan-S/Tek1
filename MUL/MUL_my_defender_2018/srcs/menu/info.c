/*
** EPITECH PROJECT, 2019
** defender
** File description:
** info
*/

#include "../include/my.h"
#include "../include/defender.h"
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <string.h>

void display_all_score(game_t *gt, sfVector2f pos)
{
    FILE *file = fopen(".score.txt", "r+");
    char *score;
    size_t size = 0;

    sfText_setString(gt->win.text_menu, "Score :");
    sfText_setPosition(gt->win.text_menu, pos);
    sfText_setCharacterSize(gt->win.text_menu, 40);
    sfRenderWindow_drawText(gt->win.window, gt->win.text_menu, NULL);
    while (getline(&score, &size, file) != -1 && pos.y < 1000) {
        pos.y += 50;
        sfText_setString(gt->win.text_menu, score);
        sfText_setCharacterSize(gt->win.text_menu, 30);
        sfText_setPosition(gt->win.text_menu, pos);
        sfRenderWindow_drawText(gt->win.window, gt->win.text_menu, NULL);
    }
}

void display_score_menu(game_t *gt)
{
    sfVector2f pos;

    gt->win.menu_degrees = 1;
    sfRenderWindow_drawSprite(gt->win.window, gt->image.menu_sprite, NULL);
    pos.x = gt->win.width / 2 - 100;
    pos.y = 400;
    display_all_score(gt, pos);
    pos.y = 1000;
    if (get_color(gt, pos) == 1)
        sfText_setColor(gt->win.text_menu, sfRed);
    else if (get_color(gt, pos) == 0) {
        gt->win.select_menu = -1;
        gt->win.menu_degrees = 0;
    }
    sfText_setString(gt->win.text_menu, "Retour");
    sfText_setPosition(gt->win.text_menu, pos);
    sfRenderWindow_drawText(gt->win.window, gt->win.text_menu, NULL);
}
