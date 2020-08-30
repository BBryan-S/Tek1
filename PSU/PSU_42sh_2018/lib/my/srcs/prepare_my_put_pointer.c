/*
** EPITECH PROJECT, 2018
** prepare_my_put_pointer.c
** File description:
** prepare_my_put_pointer
*/

#include <stdarg.h>
#include "lib.h"

int prepare_my_put_pointer(va_list list)
{
    unsigned int pointer = va_arg(list, unsigned int);

    if (pointer == 0) {
        my_putstr("(nil)");
        return (0);
    }
    my_putstr("0x");
    my_put_nbr_base(pointer, "0123456789abcdef");
    return (0);
}