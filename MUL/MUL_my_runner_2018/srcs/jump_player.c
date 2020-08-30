/*
** EPITECH PROJECT, 2018
** MUL_my_runner_2018
** File description:
** jump_player.c
*/

#include <SFML/Graphics.h>
#include <SFML/Graphics/RenderWindow.h>
#include <SFML/Graphics/Texture.h>
#include <SFML/Graphics/Sprite.h>
#include "my_runner.h"

void move_up(my_player *player)
{
    player->time = sfClock_getElapsedTime(player->clock);
    player->seconds = sfTime_asMicroseconds(player->time) / 10000;
    if (player->seconds < 40) {
        player->position.y = player->position.y - 3;
        sfSprite_setPosition(player->player_jump, player->position);
    } else {
        sfClock_restart(player->clock);
        player->jump = -1;
    }
}

void move_down(my_player *player)
{
    player->player_rect.left = 65;
    player->player_rect.width = 68;
    sfSprite_setTextureRect(player->player_jump, player->player_rect);
    player->time = sfClock_getElapsedTime(player->clock);
    player->seconds = sfTime_asMicroseconds(player->time) / 10000;
    if (player->seconds < 40) {
        player->position.y = player->position.y + 3;
        sfSprite_setPosition(player->player_jump, player->position);
    } else {
        sfClock_restart(player->clock);
        player->jump = 0;
    }
}

void jump_player(my_runner *run, my_player *player)
{
    sfClock_restart(player->clock);
    player->player_rect.left = 0;
    player->player_rect.width = 60;
    sfSprite_setTextureRect(player->player_jump, player->player_rect);
    while (sfRenderWindow_isOpen(run->window) && player->jump != 0) {
        if (player->jump == 1)
            move_up(player);
        else if (player->jump == -1)
            move_down(player);
        my_display_jump(run, player);
        move_back(run);
        my_event(run, player);
    }
    player->player_rect.left = 0;
    player->player_rect.width = 80;
}