/*
** EPITECH PROJECT, 2018
** main.c
** File description:
** main
*/

#include "../include/bsq.h"
#include "../include/my.h"
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

int main(int ac, char **av)
{
    char *buffer;
    int len;

    if (ac < 2)
        return (84);
    buffer = read_file(av[1], &len);
    find_biggest_square(buffer, get_nb_line(buffer), get_line_len(buffer), len);
    return (0);
}
