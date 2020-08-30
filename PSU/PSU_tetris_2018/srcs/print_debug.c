/*
** EPITECH PROJECT, 2018
** PSU_tetris_2018
** File description:
** print_debug.c
*/

#include <stdlib.h>
#include <ncurses.h>
#include "lib.h"
#include "tetris.h"

void print_key(setting_t set)
{
    printw("Key Left :  %c\nKey Right :  %c\n", set.left, set.right);
    printw("Key Turn :  %c\nKey Drop :  %c\n", set.turn, set.drop);
    printw("Key Quit :  %c\nKey Pause :  %c\n", set.quit, set.pause);
}

void print_tetri_name(tetriminos_t min)
{
    for (int a = 0; min.name[a] && min.name[a] != '.'; a++)
        printw("%c", min.name[a]);
    if (min.y == -1 || min.x == -1 || min.color == -1)
        printw(" :  Error\n");
    else if (min.tetrimino == NULL)
        printw(" :  Error\n");
    else {
        printw(" :  Size %d*%d :  ", min.x, min.y);
        printw("Color %d :\n", min.color);
        for (int a = 0; min.tetrimino[a]; a++)
            printw("%s\n", min.tetrimino[a]);
    }
}

void print_tetriminos(tetris_t tet)
{
    for (int a = 0; a < tet.nb_tetriminos; a++) {
        printw("Tetriminos :  Name ");
        print_tetri_name(tet.tetriminos[a]);
    }
}

void print_debug(tetris_t tet)
{
    printw("*** DEBUG MODE ***\n");
    print_key(tet.setting);
    if (tet.setting.next == 1)
        printw("Next :  Yes\n");
    else
        printw("Next :  No\n");
    printw("Level :  %d\n", tet.setting.level);
    printw("Size :  %d*%d\n", tet.setting.height, tet.setting.width);
    printw("Tetriminos :  %d\n", tet.nb_tetriminos);
    print_tetriminos(tet);
    printw("Press any key to start Tetris");
}