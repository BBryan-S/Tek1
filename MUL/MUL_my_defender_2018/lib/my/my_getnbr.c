/*
** EPITECH PROJECT, 2018
** my_getnbr
** File description:
** get only number
*/

#include <unistd.h>

int my_strlen(char const *str);

int boucl_nbr(char const *str, int i, int set, int *test)
{
    if (47 < str[i] && str[i] < 59) {
        *test = 1;
        set = (set * 10) + (str[i] - 48);
    }
    return (set);
}

int test_nb(char a)
{
    if (a > 47 && a < 59)
        return (1);
    else if (a == '+' || a == '-')
        return (2);
    return (0);
}

int my_getnbr(char const *str)
{
    int set = 0;
    int fact = 1;
    int test = 0;

    if (str == NULL)
        return (84);
    for (int i = 0; i <= my_strlen(str); i = i + 1) {
        set = boucl_nbr(str, i, set, &test);
        if (test && !test_nb(str[i+1]))
            break;
        if ((str[i] == '-' && test_nb(str[i+1]) > 0))
            fact = fact * -1;
    }
    set = set * fact;
    if (set < -2147483647 || set > 2147483647)
        return (0);
    return (set);
}
