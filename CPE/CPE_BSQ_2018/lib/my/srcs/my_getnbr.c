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
    int sign = 0;
    int a = 0;

    for (; str[a] != '\0' && (str[a] < '0' || str[a] > '9'); a = a + 1) {
        if (str[a] != '+' && str[a] != '-')
            return (nbr);
        else if (str[a] == '-' && sign == 0)
            sign = 1;
        else
            sign = 0;
    }
    for (; str[a] != '\0' && str[a] >= '0' && str[a] <= '9'; a = a + 1)
        nbr = (nbr * 10) + (str[a] - 48);
    if (sign == 1)
        nbr = nbr * (-1);
    return (nbr);
}
