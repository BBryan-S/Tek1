/*
** EPITECH PROJECT, 2018
** my_alloc.c
** File description:
** my_alloc
*/

#include <unistd.h>
#include <stdlib.h>

char *my_alloc(int len)
{
    char *dest = malloc(sizeof(char) * (len + 1));

    if (!dest)
        return (NULL);
    for (int a = 0; a <= len; a = a + 1)
        dest[a] = '\0';
    return (dest);
}
