/*
** EPITECH PROJECT, 2018
** my_getnbr.c
** File description:
** my_getnbr
*/

#include <unistd.h>

int my_getnbr(char const *str)
{
    int nbr = 0;

    for (int x = 0; str[x] != '\0'; x = x + 1) {
        if (str[x] < '0' || str[x] > '9')
            return (0);
        if (x > 10 || (x == 10 && str[0] > '2'))
            return (0);
    }
    for (int a = 0; str[a] != '\0'; a = a + 1)
        nbr = (nbr * 10) + (str[a] - 48);
    if (nbr > 2147483647)
        return (0);
    return (nbr);
}
