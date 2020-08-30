/*
** EPITECH PROJECT, 2018
** my_strncmp
** File description:
** compare n string
*/

#include <stdio.h>

int my_strncmp(char const *s1, char const *s2, int n, int a)
{
    int rest = 0;
    for (int i = n; i < a && (s1[i] != '\0' || s2[i] != '\0'); i = i + 1) {
        if (s1[i] != s2[i] && s2[i] != '*') {
            rest = s1[i] - s2[i];
            return (rest);
        }
    }
    return (rest);
}
