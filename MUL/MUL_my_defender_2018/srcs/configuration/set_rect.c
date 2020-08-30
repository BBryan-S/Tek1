/*
** EPITECH PROJECT, 2019
** rect
** File description:
** recht
*/

#include <stdlib.h>
#include "../include/my.h"
#include "../include/defender.h"

void set_panel_rect(sfIntRect *rect)
{
    rect->top = 2960;
    rect->left = 0;
    rect->width = 470;
    rect->height = 220;
}

void set_enemi_rect(sfIntRect *rect)
{
    for (int i = 0; i < 5; i++) {
        rect[i].top = 420 * i;
        rect[i].left = 0;
        rect[i].width = 140;
        rect[i].height = 140;
    }
}

void set_tower_rect(sfIntRect *rect)
{
    for (int i = 0; i < 3; i++) {
        rect[i].top = 140 * i + 2100;
        rect[i].left = 0;
        rect[i].width = 140;
        rect[i].height = 140;
    }
}

void set_classic_rect(sfIntRect *rect)
{
    rect->left = 0;
    rect->height = 140;
    rect->width = 140;
}

void prepare_rect(image_t *im)
{
    set_enemi_rect(im->enemi_rect);
    set_tower_rect(im->tower_rect);
    im->chemin_rect.top = 2520;
    set_classic_rect(&im->chemin_rect);
    im->obj_rect.top = 2660;
    im->spawn_rect.top = 2800;
    set_classic_rect(&im->obj_rect);
    set_classic_rect(&im->spawn_rect);
    set_panel_rect(&im->panel_rect);
    im->money_rect.top = 3160;
    set_classic_rect(&im->money_rect);
    im->money_rect.height = 70;
    set_panel_rect(&im->tower_panel_rect);
    im->tower_panel_rect.top = 3240;
}
