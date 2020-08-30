/*
** EPITECH PROJECT, 2018
** PSU_tetris_2018
** File description:
** print_help.c
*/

#include "lib.h"

void print_help(void)
{
    my_printf("Usage: ./tetris [options]\nOptions\n");
    my_printf(" --help Display this help\n");
    my_printf(" -L --level={num} Start Tetris at level num (def: 1)\n");
    my_printf(" -l --key-left={K} Move the tetrimino LEFT ");
    my_printf("using the K key (def: left arrow)\n");
    my_printf(" -r --key-right={K} Move the tetrimino ");
    my_printf("RIGHT using the K key (def: right arrow)\n");
    my_printf(" -t --key-turn={K} TURN the tetrimino clockwise ");
    my_printf("90d using the K key (def: top arrow)\n");
    my_printf(" -d --key-drop={K} DROP the tetrimino using the ");
    my_printf("K key (def: down arrow)\n");
    my_printf(" -q --key-quit={K} QUIT the game using the ");
    my_printf("K key (def: ‘q’ key)\n -p --key-pause={K} PAUSE/");
    my_printf("RESTART the game using the K key (def: space bar)\n");
    my_printf(" --map-size={row,col} Set the numbers of rows and ");
    my_printf("columns of the map (def: 20,10)\n");
    my_printf(" -w --without-next Hide next tetrimino (def: false)\n");
    my_printf(" -D --debug Debug mode (def: false)\n");
}