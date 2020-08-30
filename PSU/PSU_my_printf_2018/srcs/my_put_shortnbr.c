/*
** EPITECH PROJECT, 2018
** my_put_shortnbr.c
** File description:
** my_put_shortnbr
*/

#include <stdarg.h>
#include "../include/my.h"

int my_put_shortnbr(short nbr)
{
    if (nbr < 0) {
        my_putchar('-');
        my_put_shortnbr(nbr * -1);
    }
    else if (nbr <= 9)
        my_putchar(nbr + 48);
    else {
        my_put_shortnbr(nbr / 10);
        my_put_shortnbr(nbr % 10);
    }
    return (0);
}

int prepare_my_put_shortnbr(va_list list)
{
    my_put_shortnbr(va_arg(list, int));
    return (0);
}