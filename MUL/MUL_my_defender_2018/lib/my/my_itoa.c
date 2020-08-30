/*
** EPITECH PROJECT, 2019
** itoa
** File description:
** itoa
*/

#include "../../include/my.h"

char *my_itoa(int base)
{
    char *res = my_alloc(13);
    int i = 0;

    res[0] = '0';
    for (; base > 9; i++) {
        res[i] = (base % 10) + 48;
        base = base / 10;
    }
    if (base != 0) {
        res[i] = base + 48;
        i++;
    }
    return (my_revstr(res));
}
