/*
** EPITECH PROJECT, 2018
** MUL_my_runner_2018
** File description:
** usage.c
*/

#include <unistd.h>

int display_usage(int ac)
{
    if (ac < 2) {
        write(1, "./my_runner: bad arguments: 0 ", 31);
        write(1, "given but 1 is required\nRetry with -h\n", 39);
        return (84);
    } else {
        write(1, "Runner created with CSFML\n\n", 28);
        write(1, "USAGE\n  ./my_runner map.txt\n\n", 30);
        write(1, "OPTION\n", 8);
        write(1, "-h               Print the usage and quit\n\n", 44);
        write(1, "USER INTERACTIONS\nSPACE_KEY        Jump.\n", 42);
    }
    return (0);
}