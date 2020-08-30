/*
** EPITECH PROJECT, 2018
** PSU_tetris_2018
** File description:
** change_three.c
*/

#include "tetris.h"

int change_debug(char **arg, tetris_t *tet, int pos)
{
    if (!arg[pos])
        return (-1);
    tet->setting.debug = 1;
    return (0);
}