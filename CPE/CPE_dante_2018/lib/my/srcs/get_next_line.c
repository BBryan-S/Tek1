/*
** EPITECH PROJECT, 2018
** CPE_getnextline_2018
** File description:
** get_next_line.c
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "get_next_line.h"
#include "lib.h"

int is_line(char *str)
{
    if (!str)
        return (-1);
    for (int a = 0; str[a]; a = a + 1) {
        if (str[a] == '\n')
            return (1);
    }
    return (0);
}

char *read_line(char *str)
{
    int len = my_strlen(str);
    char *dest = my_alloc(len);

    if (!str)
        return (NULL);
    for (int a = 0; str[a]; str[a++] = '\0')
        dest[a] = str[a];
    if (is_line(dest) == 0) {
        free(str);
        return (dest);
    }
    for (len = 0; dest[len] && dest[len] != '\n'; len = len + 1);
    dest[len++] = '\0';
    for (int a = 0; dest[len]; len = len + 1) {
        str[a++] = dest[len];
        dest[len] = '\0';
    }
    return (dest);
}

char *my_realloc(char *str1, char buffer[])
{
    int len = my_strlen(str1) + my_strlen(buffer);
    char *dest = my_alloc(len);
    int a = 0;

    if (len == 0 || !dest)
        return (NULL);
    if (str1) {
        for (; str1[a]; a = a + 1)
            dest[a] = str1[a];
        free(str1);
    }
    for (int b = 0; buffer[b] != '\0'; b = b + 1) {
        dest[a] = buffer[b];
        a = a + 1;
    }
    return (dest);
}

char *get_next_line(int fd)
{
    static char *stock;
    char buffer[READ_SIZE + 1];
    int len = 0;

    if (fd == -1)
        return (NULL);
    if (stock && is_line(stock) == 1)
        return (read_line(stock));
    len = read(fd, buffer, READ_SIZE);
    buffer[len] = '\0';
    if (len == 0 && !stock)
        return (NULL);
    stock = my_realloc(stock, buffer);
    if (is_line(stock) == 1 || len < READ_SIZE)
        return (read_line(stock));
    else
        return (my_realloc(stock, get_next_line(fd)));
}