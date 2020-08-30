/*
** EPITECH PROJECT, 2018
** my_strdup
** File description:
** create malloc string
*/

#include <stdlib.h>

int my_strlen(char const *str);

char *my_alloc(int size);

char *my_strdup(char const *str)
{
    char *buff;
    int i = 0;

    buff = my_alloc(my_strlen(str) + 1);
    while (str[i] != '\0') {
        buff[i] = str[i];
        i = i + 1;
    }
    buff[i] = '\0';
    return (buff);
}
