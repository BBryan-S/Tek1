/*
** EPITECH PROJECT, 2018
** PSU_minishell2_2018
** File description:
** command_list.c
*/

#include <stdlib.h>
#include "lib.h"
#include "minishell.h"

void add_list(char buffer[9], char *str)
{
    short a = 0;

    for (; str[a]; a++)
        buffer[a] = str[a];
    buffer[a] = '\0';
}

void command_list(function_s *fct)
{
    add_list (fct->list[0], "env");
    fct->com_list[0] = my_display_env;
    add_list(fct->list[1], "setenv");
    fct->com_list[1] = my_setenv;
    add_list(fct->list[2], "unsetenv");
    fct->com_list[2] = my_unsetenv;
    add_list(fct->list[3], "cd");
    fct->com_list[3] = my_cd;
    add_list(fct->list[4], "exit");
    fct->com_list[4] = my_exit;
    add_list(fct->list[5], "echo");
    fct->com_list[5] = echo;
    add_list(fct->list[6], "ls");
    fct->com_list[6] = my_ls;
}