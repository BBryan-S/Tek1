/*
** EPITECH PROJECT, 2018
** my_str_to_word_array
** File description:
** string to array
*/

#include <stdlib.h>
#include <unistd.h>

int my_putstr(char const *str);

void my_putchar(char c);

int isletter2(char str)
{
    if (('A' <= str && str <= 'Z') || ('a' <= str && str <= 'z'))
        return (1);
    else if ('0' <= str && str <= '9')
        return (2);
    else
        return (0);
}

int count_str(char const *str)
{
    int i = 0;
    int count = 0;

    while (str[i] != '\0') {
        for ( ; str[i] != '\0' && isletter2(str[i]) == 0; i = i + 1);
        if (isletter2(str[i]) > 0)
            count = count + 1;
        for ( ; str[i] != '\0' && isletter2(str[i]) > 0; i = i + 1);
    }
    return (count);
}

char **my_str_to_word_array(char const *str)
{
    int i = 0;
    int g = 0;
    int a = 0;
    int size = count_str(str);
    char **tabl = malloc((size + 1) * sizeof(char *));

    for (a = 0; a <= size; a = a + 1) {
        tabl[a] = malloc((size + 1) * sizeof(char));
        while (isletter2(str[i]) == 0)
            i = i + 1;
        while (isletter2(str[i]) != 0) {
            tabl[a][g] = str[i];
            i = i + 1;
            g = g + 1;
        }
        g = 0;
    }
    tabl[a - 1] = NULL;
    return (tabl);
}
