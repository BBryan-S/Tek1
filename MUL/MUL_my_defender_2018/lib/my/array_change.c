/*
** EPITECH PROJECT, 2019
** array
** File description:
** array
*/

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

int my_strcmp(char *, char *);
int my_strlen(char *);
char *my_strcpy(char *, char const *);
char *my_alloc(int);

char **push_arr(char **array, char *str)
{
    int count = 0;
    char **stock;
    int i = 0;

    for (; array[count] != NULL; count++);
    stock = malloc(sizeof(char *) * (count + 3));
    for (; i < count; i++)
        stock[i] = array[i];
    stock[i] = str;
    stock[i + 1] = NULL;
    return (stock);
}

char **pull_arr(char **array, char *str)
{
    int count = 0;
    int i = 0;
    int found = 0;

    for (; array[i + 1] != NULL; i++) {
        if (my_strcmp(array[i], str) == 0)
            count++;
        array[i] = array[i + count];
    }
    array[i + 1 - count] = NULL;
    return (array);
}

char *push_string(char *str, char a, int pos)
{
    int len = my_strlen(str);
    char *stock = my_alloc(len + 1);

    my_strcpy(stock, str);
    if (pos < 0 || pos > len)
        pos = len - 1;
    str[pos] = a;
    for (int i = pos; i < len; i++) {
        str[i + 1] = stock[i];
    }
    str[len + 1] = '\0';
    return (str);
}

char *pull_string(char *str, char a)
{
    int len = my_strlen(str);
    char *stock = my_alloc(len);
    int i = 0;

    for (int j = 0; str[j] != '\0'; j++) {
        if (str[j] != a) {
            stock[i] = str[j];
            i++;
        }
    }
    stock[i] = '\0';
    return (stock);
}
