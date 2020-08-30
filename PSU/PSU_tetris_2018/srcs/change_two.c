/*
** EPITECH PROJECT, 2018
** PSU_tetris_2018
** File description:
** change_two.c
*/

#include "lib.h"
#include "tetris.h"

int change_drop(char **arg, tetris_t *tet, int pos)
{
    if (!arg[pos + 1] || my_strlen(arg[pos + 1]) != 1)
        return (-1);
    tet->setting.drop = arg[pos + 1][0];
    return (0);
}

int change_quit(char **arg, tetris_t *tet, int pos)
{
    if (!arg[pos + 1] || my_strlen(arg[pos + 1]) != 1)
        return (-1);
    tet->setting.quit = arg[pos + 1][0];
    return (0);
}

int change_pause(char **arg, tetris_t *tet, int pos)
{
    if (!arg[pos + 1] || my_strlen(arg[pos + 1]) != 1)
        return (-1);
    tet->setting.left = arg[pos + 1][0];
    return (0);
}

int change_size(char **arg, tetris_t *tet, int pos)
{
    char **size;
    int y = 0;
    int x = 0;

    if (!arg[pos + 1])
        return (-1);
    size = my_str_to_word_array(arg[pos + 1], ',');
    if (!size || !size[1])
        return (-1);
    y = my_getnbr(size[0]);
    x = my_getnbr(size[1]);
    if (y < 1 || x < 1)
        return (-1);
    tet->setting.height = y;
    tet->setting.width = x;
    return (0);
}

int change_next(char **arg, tetris_t *tet, int pos)
{
    if (!arg[pos])
        return (-1);
    tet->setting.next = 0;
    return (0);
}