/*
** EPITECH PROJECT, 2019
** 42sh
** File description:
** super outil !
*/

#include <stdlib.h>
#include <stdio.h>
#include "minishell.h"
#include "lib.h"
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <dirent.h>

int is_dir(char *path)
{
    if (opendir(path) != NULL)
        return (1);
    return (0);
}

char *get_all_pwd(char **env)
{
    int a = 0;
    char **tab;
    char *dest;

    for (; env[a] && strncmp(env[a], "PWD=", 4) != 0; a++);
    if (!env[a])
        return (NULL);
    tab = my_str_to_word_array(env[a], '=');
    if (!tab || !tab[1])
        return (NULL);
    dest = my_strdup(tab[1]);
    if (!dest)
        return (NULL);
    return (dest);
}

int is_user(char *str, char **env)
{
    int a = 0;
    int cmp = 0;
    char **tab;

    for (; env[a] && strncmp(env[a], "USER=", 5) != 0; a++);
    if (!env[a])
        return (FAILURE);
    tab = my_str_to_word_array(env[a], '=');
    if (strcmp(str, tab[1]) == 0)
        cmp = 1;
    return (cmp);
}

char *get_my_pwd(char **env)
{
    int a = 0;
    char **tab;
    char *dest;

    for (; env[a] && strncmp(env[a], "PWD=", 4) != 0; a++);
    if (!env[a])
        return (NULL);
    tab = my_str_to_word_array(env[a], '=');
    a = 0;
    for (int b = 0; tab[1][b] && a < 3; b++) {
        if (tab[1][b] == '/')
            a++;
        if (a == 3)
            tab[1][b] = '\0';
    }
    dest = my_strdup(tab[1]);
    return (dest);
}

char *get_name(mysh_s *mysh)
{
    int i = 0;
    char *str;

    for (; strncmp(mysh->env.environment[i], "USER", 4) != 0 &&
        mysh->env.environment[i] != NULL; i++);
    str = my_alloc(strlen(mysh->env.environment[i]));
    for (int a = 5; mysh->env.environment[i][a]; a++) {
        str[a - 5] = mysh->env.environment[i][a];
    }
    return (str);
}