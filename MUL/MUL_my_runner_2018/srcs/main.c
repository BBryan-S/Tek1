/*
** EPITECH PROJECT, 2018
** MUL_my_runner_2018
** File description:
** main.c
*/

#include <SFML/Graphics.h>
#include <SFML/Graphics/RenderWindow.h>
#include <SFML/Graphics/Texture.h>
#include <SFML/Graphics/Sprite.h>
#include <stdlib.h>
#include "my_runner.h"

void set_background_position(sfVector2f *position, float translation)
{
    if (position[0].x <= -1998)
        position[0].x = position[1].x + 1993.5;
    else
        position[0].x = position[0].x - translation;
    if (position[1].x <= -1998)
        position[1].x = position[0].x + 1998.5;
    else
        position[1].x = position[1].x - translation;
}

void set_position(my_runner *run)
{
    set_background_position(run->back1->position, 0.1);
    set_background_position(run->back2->position, 0.5);
    set_background_position(run->back3->position, 1);
    set_background_position(run->back4->position, 5);
}

void move_back(my_runner *run)
{
    run->time = sfClock_getElapsedTime(run->clock);
    run->seconds = sfTime_asMicroseconds(run->time) / 10000;
    if (run->seconds >= 1) {
        sfClock_restart(run->clock);
        set_position(run);
    }
}

int main(int ac, char **av)
{
    my_runner *run;
    my_player *player;

    if (ac < 2 || my_cmp(av[1], "-h") == 1)
        return (display_usage(ac));
    run = struct_create();
    player = player_init();
    run->music = play_music();
    while (sfRenderWindow_isOpen(run->window)) {
        my_display(run, player);
        move_back(run);
        set_player_position(player);
        my_event(run, player);
    }
    sfMusic_destroy(run->music);
    sfMusic_destroy(player->jump_sound);
    return (0);
}
