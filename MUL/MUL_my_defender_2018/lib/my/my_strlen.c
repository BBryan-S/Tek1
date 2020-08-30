/*
** EPITECH PROJECT, 2018
** my_strlen
** File description:
** return lenght
*/

#include <unistd.h>

int my_strlen(char const *str)
{
    int i = 0;

    while (str != NULL && str[i])
        i = i + 1;
    return (i);
}
