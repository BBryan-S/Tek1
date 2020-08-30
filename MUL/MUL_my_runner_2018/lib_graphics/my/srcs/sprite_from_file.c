/*
** EPITECH PROJECT, 2018
** create_my_sprite_from_file.c
** File description:
** create_my_sprite_from_file
*/

#include <SFML/Graphics.h>
#include <SFML/Graphics/RenderWindow.h>
#include <SFML/Graphics/Texture.h>
#include <SFML/Graphics/Sprite.h>
#include <stdlib.h>

sfSprite *sprite_from_file(char *filepath, double y, double x)
{
    sfTexture *texture = sfTexture_createFromFile(filepath, NULL);
    sfSprite *sprite = sfSprite_create();
    sfVector2f scale = {x, y};

    sfSprite_setTexture(sprite, texture, sfTrue);
    sfSprite_setScale(sprite, scale);
    return (sprite);
}