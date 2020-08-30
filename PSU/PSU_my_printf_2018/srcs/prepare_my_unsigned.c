/*
** EPITECH PROJECT, 2018
** my_prepare_my_unsigned.c
** File description:
** prepare_my_unsigned
*/

#include <stdarg.h>
#include "../include/my.h"

int prepare_my_put_binnbr(va_list list)
{
    my_put_nbr_base(va_arg(list, unsigned int), "01");
    return (0);
}

int prepare_my_put_octal(va_list list)
{
    my_put_nbr_base(va_arg(list, unsigned int), "01234567");
    return (0);
}

int prepare_my_put_maj_hexanbr(va_list list)
{
    my_put_nbr_base(va_arg(list, unsigned int), "0123456789ABCDEF");
    return (0);
}

int prepare_my_put_min_hexanbr(va_list list)
{
    my_put_nbr_base(va_arg(list, unsigned int), "0123456789abcdef");
    return (0);
}

int prepare_my_put_unsignednbr(va_list list)
{
    my_put_nbr_base(va_arg(list, unsigned int), "0123456789");
    return (0);
}