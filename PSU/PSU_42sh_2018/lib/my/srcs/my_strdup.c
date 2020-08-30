/*
** EPITECH PROJECT, 2018
** my_strdup.c
** File description:
** my_strdup
*/

#include <stdlib.h>
#include "lib.h"

char *my_strdup(char const *src)
{
    char *dest = my_alloc(my_strlen(src));
    int a = 0;

    for (a = 0; src[a] != '\0'; a = a + 1)
        dest[a] = src[a];
    dest[a] = '\0';
    return (dest);
}
