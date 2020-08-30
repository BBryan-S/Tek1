/*
** EPITECH PROJECT, 2018
** my_strcat
** File description:
** concatenates strings
*/

#include <stdlib.h>

int my_strlen(char *);

char *my_strcat(char *str1, char *str2)
{
    int a1 = my_strlen(str1);
    int a2 = my_strlen(str2);
    char *dest = malloc(sizeof(char) * (a1 + a2 + 1));

    dest[a1+a2] = '\0';
    for (int i = 0; i < a1; i++)
        dest[i] = str1[i];
    for (int i = a1; i < a1 + a2; i++)
        dest[i] = str2[i - a1];
    return (dest);
}
