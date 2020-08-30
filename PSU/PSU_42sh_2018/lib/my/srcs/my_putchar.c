/*
** EPITECH PROJECT, 2018
** my_putchar.c
** File description:
** my_putchar
*/

#include "lib.h"
#include <unistd.h>
#include <stdarg.h>

int prepare_my_put_percent(va_list list)
{
    (void)list;
    my_putchar('%');
    return (0);
}

int prepare_my_putchar(va_list list)
{
    my_putchar(va_arg(list, int));
    return (0);
}

void my_putchar(char c)
{
    write(1, &c, 1);
}
