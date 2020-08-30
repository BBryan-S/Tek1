/*
** EPITECH PROJECT, 2018
** PSU_minishell2_2018
** File description:
** tool.c
*/

#include <stdlib.h>
#include <string.h>
#include "lib.h"

void my_free(char **tab)
{
    if (tab) {
        for (int a = 0; tab[a]; a++)
            free(tab[a]);
        free(tab);
    }
}

void rem_tab(char *str)
{
    for (int i = 0; str[i] != '\0'; i++)
        if (str[i] == '\t')
            str[i] = ' ';
}

void remove_space_line(char *str)
{
    int a = 0;
    int b = 0;

    rem_tab(str);
    for (; str[a] && str[a] == ' '; a++);
    if (a != 0) {
        for (b = a; str[b]; b++)
            str[b - a] = str[b];
        str[b - a] = '\0';
    }
    for (a = 0; str[a]; a++);
    for (a = a - 1; a >= 0 && str[a] == ' '; a--);
    str[a + 1] = '\0';
}

char **remove_space(char **tab)
{
    for (int a = 0; tab[a] && tab[a][0] != '"'; a++) {
        remove_space_line(tab[a]);
    }
    return (tab);
}

char *rem_space(char *str)
{
    char *buffer = my_alloc(strlen(str) + 1);
    int j = 0;

    for (int i = 0; str[i] != '\0'; i++)
        if (str[i] != ' ') {
            buffer[j] = str[i];
            j++;
        }
    return (buffer);
}