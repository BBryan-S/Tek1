/*
** EPITECH PROJECT, 2019
** 42sh
** File description:
** type
*/

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include "minishell.h"
#include "lib.h"

int check_element(char **parser, char *element)
{
    for (int i = 0; parser[i] != NULL; i++)
        if (my_strcmp(parser[i], element) == 0)
            return (1);
    return (0);
}

int get_type(char **parser, char **path, char **env)
{
    if (check_element(parser, ">>") == 1)
        return (1);
    if (check_element(parser, "<<") == 1)
        return (2);
    if (check_element(parser, ">") == 1)
        return (3);
    if (check_element(parser, "<") == 1)
        return (4);
    return (0);
}

int send_function(int type, char **parser, char **path, char **env)
{
    if (type > 0 && type <= 4)
        return (redirection(type, parser, path, env));
    else if (type > 4)
        return (0);
    return (0);
}
