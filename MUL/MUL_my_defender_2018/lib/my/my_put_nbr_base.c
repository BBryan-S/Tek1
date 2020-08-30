/*
** EPITECH PROJECT, 2018
** my_put_nbr_base
** File description:
** convert base
*/

#include <unistd.h>

int my_strlen(char const *c);

int my_put_nbr_base(int nbr, char const *base, int a)
{
    int len = my_strlen(base);

    if (base == NULL)
        return (0);
    if (nbr < 0) {
        write(1, "-", 1);
        my_put_nbr_base((nbr * (-1)), base, 0);
    }
    else if (nbr < len)
        write(1, &base[nbr], 1);
    else {
        my_put_nbr_base((nbr / len), base, 0);
        my_put_nbr_base((nbr % len), base, 0);
    }
    return (0);
}
