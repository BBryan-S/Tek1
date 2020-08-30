/*
** EPITECH PROJECT, 2018
** my_putstr.c
** File description:
** my_putstr
*/

#include <unistd.h>

int my_putstr(char const *str)
{
    for (int a = 0; str != NULL && str[a] != '\0'; a = a + 1)
        write(1, &str[a], 1);
    return (0);
}
