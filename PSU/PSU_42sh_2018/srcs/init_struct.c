/*
** EPITECH PROJECT, 2018
** PSU_minishell2_2018
** File description:
** init_struct.c
*/

#include <stdlib.h>
#include "lib.h"
#include "minishell.h"

int my_strcompare(char const *str, char const *cmp)
{
    int compare = 0;

    if (!str || !str[0])
        return (-1);
    for (int a = 0; cmp[a]; a++) {
        compare = cmp[a] - str[a];
        if (compare != 0 || str[a] == '\0')
            return (-1);
    }
    return (0);
}

char **get_path(char **env)
{
    char **dest;
    int a = 0;

    for (; env[a] && my_strcompare(env[a], "PATH=") != 0; a++);
    if (env[a] == NULL)
        env[a] = "/usr/bin:/bin";
    dest = my_str_to_word_array(env[a], ':');
    for (a = 0; dest[0][a + 5]; a++)
        dest[0][a] = dest[0][a + 5];
    dest[0][a] = '\0';
    return (dest);
}

char **copy_env(char **env)
{
    char **dest;
    int nb_line = 0;

    for (; env[nb_line] != NULL; nb_line++);
    dest = malloc(sizeof(char *) * (nb_line + 1));
    if (!dest)
        return (NULL);
    for (int a = 0; env[a] != NULL; a++) {
        dest[a] = my_strdup(env[a]);
        if (!dest[a])
            return (NULL);
    }
    dest[nb_line] = NULL;
    return (dest);
}

mysh_s init_struct(char **env)
{
    mysh_s mysh;

    mysh.env.environment = copy_env(env);
    if (mysh.env.environment == NULL)
        return (mysh);
    mysh.env.path = get_path(mysh.env.environment);
    command_list(&mysh.fct);
    return (mysh);
}
