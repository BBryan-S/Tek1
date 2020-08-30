/*
** EPITECH PROJECT, 2018
** main.c
** File description:
** main
*/

#include <stdlib.h>
#include "../include/my.h"
#include <stdio.h>

int get_line_len(char *str)
{
    int len = 0;

    for ( ; str[len] && str[len] != '\n'; len = len + 1);
    return (len);
}

int get_nb_line(char *str)
{
    int len = 0;

    for (int a = 0; str[a]; a = a + 1)
        if (str[a] == '\n')
            len = len + 1;
    return (len);
}
