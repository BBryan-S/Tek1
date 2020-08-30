/*
** EPITECH PROJECT, 2018
** my_strdup.c
** File description:
** my_strdup
*/

#include <stdlib.h>

int my_strlen(char const *str);

char *my_strdup(char const *src)
{
    char *dest = malloc(sizeof(char) * (my_strlen(src) + 1));
    int a = 0;

    for (a = 0; src[a] != '\0'; a = a + 1)
        dest[a] = src[a];
    dest[a] = '\0';
    return (dest);
}
