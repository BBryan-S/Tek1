/*
** EPITECH PROJECT, 2018
** my_printf.c
** File description:
** my_printf
*/

#include <stdlib.h>
#include <stdarg.h>
#include "../include/my.h"
#include <stdio.h>

int (**pointer_init())()
{
    int (**f)() = malloc(sizeof(*f) * (15));

    f[0] = prepare_my_putstr;
    f[1] = prepare_my_putchar;
    f[2] = prepare_my_put_nbr;
    f[3] = prepare_my_put_nbr;
    f[4] = prepare_my_put_octal;
    f[5] = prepare_my_put_binnbr;
    f[6] = prepare_my_put_min_hexanbr;
    f[7] = prepare_my_put_maj_hexanbr;
    f[8] = prepare_my_put_unsignednbr;
    f[9] = prepare_my_put_pointer;
    f[10] = prepare_my_put_shortnbr;
    f[11] = prepare_my_put_longnbr;
    f[12] = flags_ss;
    f[13] = prepare_my_put_percent;
    return (f);
}

int check_flags(char c, char *str)
{
    int a = 0;

    for ( ; str[a] && str[a] != c; a = a + 1);
    return (a);
}

int check_char(char *str, int *a)
{
    char *char_flags = "scidobxXuphlS%";
    int flags = -1;

    if (str[*a] == '%') {
            *a = *a + 1;
            flags = check_flags(str[*a], char_flags);
    } else
        my_putchar(str[*a]);
    if (flags == my_strlen(char_flags)) {
        my_putchar('%');
        my_putchar(str[*a]);
        flags = -1;
    }
    return (flags);
}

int my_printf(char *str, ...)
{
    int (**f)() = pointer_init();
    int flags;
    va_list list;

    if (!f || !str)
        return (84);
    va_start(list, str);
    for (int a = 0; str[a]; a = a + 1) {
            flags = check_char(str, &a);
            if (flags >= 0)
                (*f[flags])(list);
    }
    va_end(list);
    free(f);
    return (0);
}
