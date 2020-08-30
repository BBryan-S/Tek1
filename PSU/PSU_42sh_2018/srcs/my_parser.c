/*
** EPITECH PROJECT, 2018
** PSU_42sh_2018
** File description:
** my_parser.c
*/

#include <stdlib.h>
#include "lib.h"
#include "minishell.h"

int my_strstr(char const *str, char *c, int pos)
{
    int a = pos;
    int b = 0;

    for (; c[b] && str[a]; a++, b++) {
        if (str[a] != c[b])
            return (-1);
    }
    if (!str[a] && c[b])
        return (-1);
    return (0);
}

int nb_parse(char const *str, char *c)
{
    int nb = 1;

    for (int a = 0; str[a]; a++) {
        if (my_strstr(str, c, a) == SUCCESS) {
            nb++;
            a = a + my_strlen(c) - 1;
        }
    }
    return (nb);
}

char **parser_alloc(char const *str, char *c)
{
    int line = nb_parse(str, c);
    int nb = 0;
    char **dest = malloc(sizeof(char *) * (line + 1));

    line = 0;
    for (int a = 0; str[a];) {
        for (; str[a] && my_strstr(str, c, a) != 0; a++)
            nb++;
        if (str[a])
            a = a + my_strlen(c) - 1;
        dest[line] = my_alloc(nb);
        line = line + 1;
        nb = 0;
    }
    dest[line] = NULL;
    return (dest);
}

char **my_parser(char const *str, char *c)
{
    char **dest = parser_alloc(str, c);
    int y = 0;
    int len = my_strlen(c);

    for (int a = 0; str[a]; y = y + 1) {
        for (; str[a] && my_strstr(str, c, a) == 0; a = a + len);
        for (int x = 0; str[a] && my_strstr(str, c, a); a = a + 1) {
            dest[y][x] = str[a];
            x = x + 1;
        }
        for (; str[a] && my_strstr(str, c, a) == 0; a = a + len);
    }
    return (dest);
}
