/*
** EPITECH PROJECT, 2018
** my_put_nbr_base.c
** File description:
** my_put_nbr_base
*/

#include "../include/my.h"

int my_put_nbr_base(unsigned int nb, char const *base)
{
    unsigned int len = my_strlen(base);

    if (nb < len)
        my_putchar(base[nb]);
    else {
        my_put_nbr_base((nb / len), base);
        my_put_nbr_base((nb % len), base);
    }
    return (0);
}
