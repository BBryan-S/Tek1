/*
** EPITECH PROJECT, 2018
** my_strlen.c
** File description:
** my_strlen
*/

#include <unistd.h>

int my_strlen(char const *str)
{
    int a = 0;

    for (a = 0; str != NULL && str[a] != '\0'; a = a + 1);
    return (a);
}
