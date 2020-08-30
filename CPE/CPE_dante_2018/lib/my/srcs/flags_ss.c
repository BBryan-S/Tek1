/*
** EPITECH PROJECT, 2018
** my_putchar.c
** File description:
** my_putchar
*/

#include <stdarg.h>
#include "lib.h"

int flags_ss(va_list list)
{
    char *str = va_arg(list, char *);

    for (int a = 0; str[a]; a = a + 1) {
        if (str[a] < 37 || str[a] > 126) {
            my_putchar('\\');
            my_put_nbr_base(str[a], "0123456789ABCDEF");
        } else
            my_putchar(str[a]);
    }
    return (0);
}
