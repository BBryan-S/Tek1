/*
** EPITECH PROJECT, 2018
** my_putstr.c
** File description:
** my_putstr
*/

#include "lib.h"
#include <unistd.h>
#include <stdarg.h>

int prepare_my_putstr(va_list list)
{
    my_putstr(va_arg(list, char *));
    return (0);
}

int my_putstr(char const *str)
{
    for (int a = 0; str != NULL && str[a] != '\0'; a = a + 1)
        write(1, &str[a], 1);
    return (0);
}
