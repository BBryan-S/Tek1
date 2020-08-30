/*
** EPITECH PROJECT, 2018
** my_getnbr.c
** File description:
** my_getnbr
*/

#include <unistd.h>

int my_getnbr(char const *str, int *nbr)
{
    for (int x = 0; str[x]; x = x + 1) {
        if (str[x] < '0' || str[x] > '9')
            return (-1);
    }
    *nbr = 0;
    for (int a = 0; str[a] != '\0' && str[a] >= '0' && str[a] <= '9'; a = a + 1)
        *nbr = (*nbr * 10) + (str[a] - 48);
    return (0);
}
