/*
** EPITECH PROJECT, 2018
** my_show_word_array.c
** File description:
** my_show_word_array
*/

#include <stdlib.h>
#include "../include/lib.h"

int my_show_word_array(char **tab)
{
    for (int a = 0; tab != NULL && tab[a] != NULL; a = a + 1) {
        my_putstr(tab[a]);
        my_putchar('\n');
    }
    return (0);
}
