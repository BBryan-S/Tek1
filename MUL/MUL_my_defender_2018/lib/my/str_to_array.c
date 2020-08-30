/*
** EPITECH PROJECT, 2018
** my_str_to_word_array
** File description:
** string to array
*/

#include <stdlib.h>
#include <unistd.h>

char *my_alloc(int size);

char *my_strncpy(char *, char const *, int, int);

int my_strlen(char *);

char *size_word(char *str, int i, char sep)
{
    int count = 0;
    int repere = 0;
    int space = 0;
    int end = 0;
    char *stock;

    while (space < i) {
        if (repere > 0 && str[repere] == sep && str[repere - 1] != sep)
            space++;
        repere++;
    }
    for (; str[repere] == sep && str[repere] != '\0'; repere++);
    for (end = repere; str[end] != sep && str[end] != '\0'; end++);
    stock = my_alloc(end - repere);
    my_strncpy(stock, str, repere, end);
    return (stock);
}

int count_word(char *str, char sep)
{
    int count = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        if (i > 0 && str[i] == sep && str[i - 1] != sep)
            count++;
    }
    return (count + 1);
}

char **str_to_array(char *str, char sep)
{
    int word = count_word(str, sep);
    char **array = malloc(sizeof(char *) * (word + 2));

    for (int i = 0; i < word; i++) {
        array[i] = my_alloc(my_strlen(size_word(str, i, sep)));
        array[i] = size_word(str, i, sep);
    }
    return (array);
}
