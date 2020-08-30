/*
** EPITECH PROJECT, 2018
** lib.h
** File description:
** lib
*/

#ifndef _LIB_H_
#define _LIB_H_

#include <SFML/Graphics.h>
#include <SFML/Graphics/RenderWindow.h>
#include <SFML/Graphics/Texture.h>
#include <SFML/Graphics/Sprite.h>

sfRenderWindow *create_my_window(char *, int, int, int);
sfSprite *sprite_from_file(char *, double, double);

#endif