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

int my_strlen(char *str)
{
    int len = 0;

    if (!str)
        return (0);
    for (; str[len]; len = len + 1);
    return (len);
}

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
    char *dest = malloc (sizeof(char) * (len + 1));

    if (!str)
        return (NULL);
    for (int a = 0; str[a]; a = a + 1) {
        dest[a] = str[a];
        str[a] = '\0';
    }
    dest[len] = '\0';
    if (is_line(dest) == 0)
        return (dest);
    for (len = 0; dest[len] && dest[len] != '\n'; len = len + 1);
    dest[len++] = '\0';
    for (int a = 0; dest[len]; len = len + 1) {
        str[a++] = dest[len];
        dest[len] = '\0';
    }
    return (dest);
}

char *my_realloc(char *str1, char *str2)
{
    int len = my_strlen(str1) + my_strlen(str2);
    char *dest = malloc(sizeof(char) * (len + 1));
    int a = 0;

    if (len == 0 || !dest)
        return (NULL);
    if (str1) {
        for (; str1[a]; a = a + 1)
            dest[a] = str1[a];
        free(str1);
    }
    if (str2) {
        for (int b = 0; str2[b]; b = b + 1) {
            dest[a] = str2[b];
            a = a + 1;
        }
        dest[a] = '\0';
    }
    return (dest);
}

char *get_next_line(int fd)
{
    char static *stock;
    char *str = malloc(sizeof(char) * (READ_SIZE + 1));
    int len = 0;

    if (fd == -1 || !str)
        return (NULL);
    if (stock && is_line(stock) == 1)
        return (read_line(stock));
    len = read(fd, str, READ_SIZE);
    str[len] = '\0';
    if (len == 0 && !stock)
        return (NULL);
    stock = my_realloc(stock, str);
    free(str);
    if (is_line(stock) == 1 || len < READ_SIZE)
        return (read_line(stock));
    else
        return (my_realloc(stock, get_next_line(fd)));
}