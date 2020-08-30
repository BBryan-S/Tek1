/*
** EPITECH PROJECT, 2018
** main.c
** File description:
** main
*/

#include "../include/lib.h"
#include "../include/sokoban.h"
#include <stdio.h>
#include <ncurses.h>

int main(int ac, char **av)
{
    char *str;
    char **map;

    if (ac < 2)
        return (84);
    if (my_strcmp(av[1], "-h") == 0)
        return (display_usage());
    str = read_file(av[1]);
    if (!str)
        return (84);
    map = my_parser(str, '\n');
    if (!map || check_map(map) == 84)
        return (84);
    initscr();
    keypad(stdscr, TRUE);
    noecho();
    return (my_game(map));
}
