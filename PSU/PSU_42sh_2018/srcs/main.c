/*
** EPITECH PROJECT, 2018
** PSU_minishell2_2018
** File description:
** main.c
*/

#include <stdlib.h>
#include <stdio.h>
#include "minishell.h"
#include "lib.h"

int main(int ac, char **av, char **env)
{
    mysh_s mysh = init_struct(env);
    int a = 0;

    if (ac > 1 || !av)
        return (ERROR);
    if (!mysh.env.path || !mysh.env.environment)
        return (ERROR);
    while (a != EXIT && a != ERROR) {
        my_printf("$>");
        a = get_command(&mysh);
    }
    return (0);
}
