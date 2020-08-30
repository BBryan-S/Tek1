/*
** EPITECH PROJECT, 2018
** PSU_tetris_2018
** File description:
** main.c
*/

#include <ncurses.h>
#include "lib.h"
#include "tetris.h"

int search_com(char **arg, tetris_t *tet, int pos)
{
    for (int a = 0; a < 11; a++) {
        if (my_strcmp(arg[pos], tet->small_command[a]) == 0)
            return ((*tet->com_list[a]) (arg, tet, pos));
        if (my_strcmp(arg[pos], tet->large_command[a]) == 0)
            return ((*tet->com_list[a]) (arg, tet, pos));
    }
    return (-1);
}

int set_arg(char **arg, tetris_t *tet)
{
    for (int a = 1; arg[a]; a++) {
        search_com(arg, tet, a);
        if (tet->setting.help == 1)
            return (2);
    }
    return (0);
}

int main(int ac, char **av)
{
    tetris_t tet = set_struct();

    if (ac > 1 && set_arg(av, &tet) == 2)
        return (0);
    if (get_tetriminos(&tet) == 84)
        return (84);
    initscr();
    keypad(stdscr, TRUE);
    noecho();
    if (tet.setting.debug == 1)
        print_debug(tet);
    getch();
    endwin();
    return (0);
}