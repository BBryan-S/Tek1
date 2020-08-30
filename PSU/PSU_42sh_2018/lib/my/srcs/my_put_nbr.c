/*
** EPITECH PROJECT, 2018
** my_put_nbr.c
** File description:
** my_put_nbr
*/

#include "lib.h"
#include <unistd.h>
#include <stdarg.h>

int prepare_my_put_nbr(va_list list)
{
    my_put_nbr(va_arg(list, int));
    return (0);
}

int my_put_nbr(int nb)
{
    if (nb == -2147483648) {
        my_putstr("-2147483648");
        return (0);
    }
    if (nb < 0) {
        my_putchar('-');
        my_put_nbr(nb * -1);
    }
    else if (nb <= 9)
        my_putchar(nb + 48);
    else {
        my_put_nbr(nb / 10);
        my_put_nbr(nb % 10);
    }
    return (0);
}
