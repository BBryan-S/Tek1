/*
** EPITECH PROJECT, 2019
** 42sh
** File description:
** ls
*/

#include "lib.h"
#include "minishell.h"
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>

int my_ls(char **tab, mysh_s *mysh)
{
   char *path = get_my_pwd(mysh->env.environment);

   for (int i = 1; tab[i] != NULL; i++)
       if (strcmp(tab[i], "~") == 0)
           tab[i] = path;
    return (exec_command(tab, mysh->env.path, mysh->env.environment));
}