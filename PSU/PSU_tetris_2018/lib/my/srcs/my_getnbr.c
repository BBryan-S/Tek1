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

    for (int a = 0; str[a]; a++) {
        if (str[a] < '0' || str[a] > '9')
            return (-1);
    }
    for (int a = 0; str[a]; a++)
        nbr = (nbr * 10) + (str[a] - 48);
    return (nbr);
}
