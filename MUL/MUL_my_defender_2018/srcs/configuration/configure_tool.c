/*
** EPITECH PROJECT, 2019
** configure
** File description:
** configure
*/

#include <stdlib.h>
#include "../../include/my.h"
#include "../../include/defender.h"

void set_tex_sprite(sfTexture *texture, sfSprite *sprite, char *path)
{
    texture = sfTexture_createFromFile(path, NULL);
    sfSprite_setTexture(sprite, texture, sfTrue);
}

