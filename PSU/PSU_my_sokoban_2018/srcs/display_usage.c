/*
** EPITECH PROJECT, 2018
** display_usage.c
** File description:
** display_usage
*/

#include "../include/lib.h"

int display_usage(void)
{
    my_putstr("USAGE\n     ./my_sokoban map\n");
    my_putstr("DESCRIPTION\n     map  file representing the warehouse map, ");
    my_putstr("containing ‘#’ for walls,\n          ‘P’ for the player, ");
    my_putstr("‘X’ for boxes and ‘O’ for storage locations.\n");
    return (0);
}