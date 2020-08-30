/*
** EPITECH PROJECT, 2018
** MUL_my_runner_2018
** File description:
** player_init.c
*/

#include <SFML/Graphics.h>
#include <SFML/Graphics/RenderWindow.h>
#include <SFML/Graphics/Texture.h>
#include <SFML/Graphics/Sprite.h>
#include <stdlib.h>
#include "my_runner.h"
#include "lib.h"

my_player *player_init(void)
{
    my_player *player = malloc(sizeof(my_player));

    player->player = sprite_from_file("Picture/player.png", 1.5, 1.5);
    player->player_jump = sprite_from_file("Picture/player_jump.png", 1.5, 1.5);
    player->player_rect.height = 98;
    player->player_rect.left = 0;
    player->player_rect.width = 80;
    player->player_rect.top = 0;
    player->clock = sfClock_create();
    player->seconds = 0;
    sfSprite_setTextureRect(player->player, player->player_rect);
    player->position.x = 20;
    player->position.y = 576;
    sfSprite_setPosition(player->player, player->position);
    sfSprite_setPosition(player->player_jump, player->position);
    player->jump = 0;
    player->jump_sound = sfMusic_createFromFile("Audio/jump.wav");
    return (player);
}