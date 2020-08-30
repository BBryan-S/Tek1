/*
** EPITECH PROJECT, 2018
** my_alloc.c
** File description:
** my_alloc
*/

#include <unistd.h>
#include <stdlib.h>

char *my_alloc(int size)
{
    char *buff = malloc(sizeof(char) * (size + 1));

    if (!buff)
        return (NULL);
    for (int i = 0; i <= size; i = i + 1)
        buff[i] = '\0';
    return (buff);
}
