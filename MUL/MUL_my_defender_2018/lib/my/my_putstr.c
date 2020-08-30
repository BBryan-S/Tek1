/*
** EPITECH PROJECT, 2018
** my_putstr
** File description:
** display string
*/

#include <unistd.h>

int my_putstr(char const *str)
{
    int i = 0;

    while (str != NULL && str[i]) {
        write(1, &str[i], 1);
        i = i + 1;
    }
    return (0);
}
