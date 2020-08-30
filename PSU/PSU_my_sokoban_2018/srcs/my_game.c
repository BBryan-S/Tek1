/*
** EPITECH PROJECT, 2018
** my_game.c
** File description:
** my_game
*/

#include <ncurses.h>
#include <stdlib.h>
#include "../include/sokoban.h"

int check_win_game(char **map)
{
    for (int a = 0; map[a]; a = a + 1) {
        if (search_char(map[a], 'O') == 1)
            return (-1);
    }
    return (0);
}

int blocked_box(char **map, int y, int x)
{
    if (map[y - 1][x] == '#' && (map[y][x - 1] == '#' || map[y][x + 1] == '#'))
        return (1);
    if (map[y + 1][x] == '#' && (map[y][x - 1] == '#' || map[y][x + 1] == '#'))
        return (1);
    return (0);
}

int check_game_over(char **map, int y)
{
    for (int x = 0; map[y][x]; x = x + 1) {
        if (map[y][x] == 'X' && blocked_box(map, y, x) == 0)
            return (0);
    }
    return (1);
}

int end_game(char **map)
{
    if (check_win_game(map) == 0)
        return (0);
    for (int a = 0; map[a]; a = a + 1) {
        if (check_game_over(map, a) == 0)
            return (-1);
    }
    return (1);
}

int my_game(char **map)
{
    char **stock = map_dup(map);
    int end = -1;

    while (end == -1) {
        print_map(map);
        refresh();
        move(0, 0);
        set_map(map, stock);
        end = end_game(map);
    }
    endwin();
    free(map);
    free(stock);
    return (end);
}