/*
** EPITECH PROJECT, 2018
** Visual Studio Live Share (Workspace)
** File description:
** display.c
*/

#include "../include/generator.h"
#include <stdlib.h>
#include <stdio.h>

void display(gen_t *gen)
{
    int count = 0;

    for (int i = 0; i < gen->y; i++) {
        for (int j = 0; j < gen->x; j++, count++) {
            if (gen->map[i][j] == WALL)
                printf("X");
            else if (gen->map[i][j] == PATH)
                printf("*");
            else
                printf(".");
        }
        if (i < gen->y - 1)
            printf("\n");
    }
}
