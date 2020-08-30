/*
** EPITECH PROJECT, 2018
** MUL_my_runner_2018
** File description:
** display.c
*/

#include <SFML/Graphics.h>
#include <SFML/Graphics/RenderWindow.h>
#include <SFML/Graphics/Texture.h>
#include <SFML/Graphics/Sprite.h>
#include <stdlib.h>
#include "my_runner.h"

void display_my_background(sfRenderWindow *window, back_s *back)
{
    sfSprite_setPosition(back->back, back->position[0]);
    sfRenderWindow_drawSprite(window, back->back, NULL);
    sfSprite_setPosition(back->back, back->position[1]);
    sfRenderWindow_drawSprite(window, back->back, NULL);
}

void my_display_jump(my_runner *run, my_player *player)
{
    display_my_background(run->window, run->back1);
    display_my_background(run->window, run->back2);
    display_my_background(run->window, run->back3);
    display_my_background(run->window, run->back4);
    sfRenderWindow_drawSprite(run->window, player->player_jump, NULL);
    sfRenderWindow_display(run->window);
    sfRenderWindow_clear(run->window, sfBlack);
}

void my_display(my_runner *run, my_player *player)
{
    display_my_background(run->window, run->back1);
    display_my_background(run->window, run->back2);
    display_my_background(run->window, run->back3);
    display_my_background(run->window, run->back4);
    sfRenderWindow_drawSprite(run->window, player->player, NULL);
    sfRenderWindow_display(run->window);
    sfRenderWindow_clear(run->window, sfBlack);
}
