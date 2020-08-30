/*
** EPITECH PROJECT, 2018
** PSU_tetris_2018
** File description:
** change_one.c
*/

#include "lib.h"
#include "tetris.h"

int display_help(char **arg, tetris_t *tet, int pos)
{
    if (!arg[pos] || !tet)
        return (84);
    print_help();
    tet->setting.help = 1;
    return (0);
}

int change_level(char **arg, tetris_t *tet, int pos)
{
    int lvl = 0;

    if (!arg[pos + 1])
        return (-1);
    lvl = my_getnbr(arg[pos + 1]);
    if (lvl == -1)
        return (-1);
    tet->setting.level = lvl;
    return (0);
}

int change_left(char **arg, tetris_t *tet, int pos)
{
    if (!arg[pos + 1] || my_strlen(arg[pos + 1]) != 1)
        return (-1);
    tet->setting.left = arg[pos + 1][0];
    return (0);
}

int change_right(char **arg, tetris_t *tet, int pos)
{
    if (!arg[pos + 1] || my_strlen(arg[pos + 1]) != 1)
        return (-1);
    tet->setting.right = arg[pos + 1][0];
    return (0);
}

int change_turn(char **arg, tetris_t *tet, int pos)
{
    if (!arg[pos + 1] || my_strlen(arg[pos + 1]) != 1)
        return (-1);
    tet->setting.turn = arg[pos + 1][0];
    return (0);
}