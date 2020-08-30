/*
** EPITECH PROJECT, 2018
** create_my_window.c
** File description:
** create_my_window
*/

#include <SFML/Graphics.h>
#include <SFML/Graphics/RenderWindow.h>
#include <SFML/Graphics/Texture.h>
#include <SFML/Graphics/Sprite.h>
#include <stdlib.h>

sfRenderWindow *create_my_window(char *name, int x, int y, int bits_per_pixel)
{
    sfVideoMode mode = {x, y, bits_per_pixel};
    sfRenderWindow *window;

    window = sfRenderWindow_create(mode, name, sfDefaultStyle, NULL);
    return (window);
}