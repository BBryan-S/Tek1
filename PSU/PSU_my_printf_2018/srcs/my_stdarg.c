/*
** EPITECH PROJECT, 2018
** my_sum_stdarg.c
** File description:
** my_sum_stdarg
*/

#include "../include/my.h"
#include <stdarg.h>

void print_arg(char c, va_list list)
{
    if (c == 'c' || c == 's') {
        if (c == 'c')
            my_putchar(va_arg(list, int));
        else
            my_putstr(va_arg(list, char *));
        my_putchar('\n');
    } else if (c == 'i') {
        my_put_nbr(va_arg(list, int));
        my_putchar('\n');
    }
}

int disp_stdarg(char *s, ...)
{
    va_list list;

    va_start(list, s);
    for (int a = 0; s[a]; a = a + 1)
        print_arg(s[a], list);
    va_end(list);
    return (0);
}

int sum_stdarg(int i, int nb, ...)
{
    int res = 0;
    va_list list;

    va_start(list, nb);
    if (i == 0) {
        for (int a = 0; a < nb; a = a + 1)
            res = res + va_arg(list, int);
    } else if (i == 1) {
        for (int a = 0; a < nb; a = a + 1)
            res = res + my_strlen(va_arg(list, char *));
    }
    va_end(list);
    return (res);
}
