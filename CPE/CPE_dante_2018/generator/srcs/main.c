/*
** EPITECH PROJECT, 2019
** dante
** File description:
** main
*/

#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include "../include/my.h"
#include "../include/generator.h"
#include <time.h>

void mapping(gen_t *gen)
{
    gen->map = malloc(sizeof(int *) * (gen->y + 1));
    for (int i = 0; i < gen->y; i++) {
        gen->map[i] = malloc(sizeof(int) * (gen->x + 1));
        for (int j = 0; j < gen->x; j++)
            gen->map[i][j] = FREE;
    }
}

int main(int ac, char **av)
{
    gen_t gen;

    srand(time(NULL));
    if (get_info(ac, av, &gen) == ERROR)
        return (ERROR);
    mapping(&gen);
    generator(&gen);
    display(&gen);
    return (0);
}
