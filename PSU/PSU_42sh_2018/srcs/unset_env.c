/*
** EPITECH PROJECT, 2018
** PSU_minishell2_2018
** File description:
** unset_env.c
*/

#include <stdlib.h>
#include "lib.h"
#include "minishell.h"

int get_nb_line(char **tab)
{
    int a = 0;

    for (; tab[a]; a++);
    return (a);
}

char **unset_env(char **tab, char **env)
{
    char **dest;
    int a = 0;
    int c = 0;

    for (; env[a] && my_strcompare(env[a], tab[1]) != SUCCESS; a++);
    if (!env[a])
        return (env);
    dest = malloc(sizeof(char *) * (get_nb_line(env)));
    if (!dest)
        return (NULL);
    for (int b = 0; env[b]; b++) {
        if (b != a)
            dest[c++] = my_strdup(env[b]);
    }
    dest[c] = NULL;
    return (dest);
}