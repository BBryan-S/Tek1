/*
** EPITECH PROJECT, 2018
** my_getnbr.c
** File description:
** my_getnbr
*/

#include "../include/lib.h"
#include <stdlib.h>

char **alloc_my_parser(char const *str, char c)
{
    char **parser;
    int len = 0;
    int y = 0;

    for (int a = 0; str[a]; a = a + 1)
        if (str[a] == c)
            len = len + 1;
    parser = malloc(sizeof(char *) * (len + 1));
    len = 0;
    for (int a = 0; str[a]; a = a + 1) {
        if (str[a] == c) {
            parser[y] = my_alloc(len + 1);
            y = y + 1;
            len = 0;
        } else
            len = len + 1;
    }
    if (len != 0)
        parser[y] = my_alloc(len + 1);
    return (parser);
}

char **my_parser(char const *str, char const c)
{
    char **parser = alloc_my_parser(str, c);
    int y = 0;
    int a = 0;

    if (!parser)
        return (NULL);
    for (int x = 0; str[a]; a = a + 1) {
        if (str[a] == c) {
            x = 0;
            y = y + 1;
        } else {
            parser[y][x] = str[a];
            x = x + 1;
        }
    }
    if (str[a - 1] == c)
        parser[y] = NULL;
    else
        parser[y + 1] = NULL;
    return (parser);
}