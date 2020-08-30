/*
** EPITECH PROJECT, 2018
** my_strcat.c
** File description:
** my_strcat
*/

#include <unistd.h>
#include <stdio.h>

char *my_strcat(char *dest, char const *src)
{
    int a = 0;

    for (a = 0; dest[a] != '\0'; a = a + 1)
    for (int b = 0; src[b] != '\0'; b = b + 1) {
        dest[a] = src[b];
        a = a + 1;
    }
    dest[a] = '\0';
    return (dest);
}
