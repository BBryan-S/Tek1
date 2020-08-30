/*
** EPITECH PROJECT, 2018
** MUL_my_runner_2018
** File description:
** my_event.c
*/

#include <SFML/Graphics.h>
#include <SFML/Graphics/RenderWindow.h>
#include <SFML/Graphics/Texture.h>
#include <SFML/Graphics/Sprite.h>
#include "my_runner.h"

int space_event(sfEvent event)
{
    if (event.type == sfEvtKeyPressed) {
        if (sfKeyboard_isKeyPressed(sfKeySpace) == sfTrue)
            return (1);
    }
    return (0);
}

int escape_event(sfEvent event)
{
    if (event.type == sfEvtKeyPressed) {
        if (sfKeyboard_isKeyPressed(sfKeyEscape) == sfTrue)
            return (1);
    }
    return (0);
}

void my_event(my_runner *run, my_player *player)
{
    while (sfRenderWindow_pollEvent(run->window, &run->event)) {
        if (run->event.type == sfEvtClosed || escape_event(run->event) == 1)
            sfRenderWindow_close(run->window);
        if (space_event(run->event) == 1 && player->jump == 0) {
            player->jump = 1;
            sfMusic_play(player->jump_sound);
            jump_player(run, player);
        }
    }
}