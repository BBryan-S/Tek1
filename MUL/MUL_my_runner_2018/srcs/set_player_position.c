/*
** EPITECH PROJECT, 2018
** MUL_my_runner_2018
** File description:
** set_player_position.c
*/

#include <SFML/Graphics.h>
#include <SFML/Graphics/RenderWindow.h>
#include <SFML/Graphics/Texture.h>
#include <SFML/Graphics/Sprite.h>
#include "my_runner.h"

void set_player_position(my_player *player)
{
    player->time = sfClock_getElapsedTime(player->clock);
    player->seconds = sfTime_asMicroseconds(player->time) / 10000;
    if (player->seconds >= 14) {
        sfClock_restart(player->clock);
        if (player->player_rect.left == (85 * 5))
            player->player_rect.left = 0;
        else
            player->player_rect.left = player->player_rect.left + 85;
        sfSprite_setTextureRect(player->player, player->player_rect);
    }
}