/*
** EPITECH PROJECT, 2018
** PSU_minishell2_2018
** File description:
** command.c
*/

#include "lib.h"
#include "minishell.h"
#include <errno.h>
#include <string.h>
#include <stdio.h>

int my_display_env(char **tab, mysh_s *mysh)
{
    if (!tab || !mysh->env.environment)
        return (ERROR);
    my_show_word_array(mysh->env.environment);
    return (SUCCESS);
}

int my_setenv(char **tab, mysh_s *mysh)
{
    if (!tab[1])
        my_show_word_array(mysh->env.environment);
    else if (check_alpha(tab[1]) == FAILURE) {
        my_printf("setenv: Variable name must contain ");
        my_printf("alphanumeric characters.\n");
    } else
        mysh->env.environment = set_env(tab, mysh->env.environment);
    return (SUCCESS);
}

int my_unsetenv(char **tab, mysh_s *mysh)
{
    if (!tab[1])
        my_printf("unsetenv: not enough argument.\n");
    else
        mysh->env.environment = unset_env(tab, mysh->env.environment);
    return (SUCCESS);
}

int my_cd(char **tab, mysh_s *mysh)
{
    char *str = my_alloc(8 + strlen(get_name(mysh)));

    if (!tab[1] || strcmp(tab[1], "~") == 0 ||
        strcmp(tab[1], "/tmp/res42") == 0) {
        str = strcat(str, "/home/");
        str = strcat(str, get_name(mysh));
        tab = realloc(tab, sizeof(char *) + sizeof(tab) + 1);
        tab[1] = str;
    }
    if (chdir(tab[1]) == FAILURE)
        printf("%s: %s.\n", tab[1], strerror(errno));
    else
        env_pwd(mysh->env.environment);
    return (SUCCESS);
}

int my_exit(char **tab, mysh_s *mysh)
{
    if (!tab)
        return (ERROR);
    return (EXIT);
}
