/*
** EPITECH PROJECT, 2018
** PSU_minishell2_2018
** File description:
** set_env.c
*/

#include <stdlib.h>
#include "minishell.h"
#include "lib.h"

int check_my_char(char c)
{
    if (c >= '0' && c <= '9')
        return (SUCCESS);
    else if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'))
        return (SUCCESS);
    return (FAILURE);
}

int check_alpha(char *s)
{
    for (int a = 0; s[a]; a++) {
        if (check_my_char(s[a]) == FAILURE)
            return (FAILURE);
    }
    return (SUCCESS);
}

char *change_line(char **tab, char *str)
{
    int len = my_strlen(tab[1]) + my_strlen(tab[2]);
    char *dest = my_alloc(len + 1);

    if (!dest)
        return (NULL);
    dest = my_strcat(dest, tab[1]);
    dest = my_strcat(dest, "=");
    dest = my_strcat(dest, tab[2]);
    return (dest);
}

char **add_line(char **tab, char **env)
{
    int len = 0;
    int a = my_strlen(tab[1]) + my_strlen(tab[2]);
    char **dest;

    for (; env[len]; len++);
    dest = malloc(sizeof(char *) * (len + 2));
    if (!dest)
        return (NULL);
    for (int a = 0; env[a]; a++)
        dest[a] = my_strdup(env[a]);
    dest[len] = my_alloc(a + 1);
    dest[len] = my_strcat(dest[len], tab[1]);
    dest[len] = my_strcat(dest[len], "=");
    dest[len] = my_strcat(dest[len], tab[2]);
    dest[len + 1] = NULL;
    return (dest);
}

char **set_env(char **tab, char **env)
{
    int a = 0;

    for (; env[a] && my_strcompare(env[a], tab[1]) != SUCCESS; a++);
    if (env[a])
        env[a] = change_line(tab, env[a]);
    else
        env = add_line(tab, env);
    return (env);
}