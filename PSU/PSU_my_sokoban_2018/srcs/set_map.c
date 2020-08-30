/*
** EPITECH PROJECT, 2018
** set_map.c
** File description:
** set_map
*/

#include <stdlib.h>
#include <ncurses.h>
#include "../include/sokoban.h"

void move_left_right(char **map, char **stock, int key)
{
    int y = 0;
    int x = 0;

    get_position(map, &y, &x);
    if (key == KEY_RIGHT)
        move_right(map, stock, y, x);
    else
        move_left(map, stock, y, x);
}

void move_up_down(char **map, char **stock, int key)
{
    int y = 0;
    int x = 0;

    get_position(map, &y, &x);
    if (key == KEY_UP)
        move_up(map, stock, y, x);
    else
        move_down(map, stock, y, x);
}

void set_map(char ** map, char **stock)
{
    int key = getch();

    if (key == 32) {
        free(map);
        my_game(stock);
    }
    if (key == KEY_RIGHT || key == KEY_LEFT)
        move_left_right(map, stock, key);
    else if (key == KEY_UP || key == KEY_DOWN)
        move_up_down(map, stock, key);
}