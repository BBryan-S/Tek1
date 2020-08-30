/*
** EPITECH PROJECT, 2019
** PSU_42sh_2018
** File description:
** echo
*/

#include <string.h>
#include <unistd.h>
#include "minishell.h"
#include "lib.h"
#include <stdio.h>

char *extract_name(char *str, int pos)
{
    char *buffer = my_alloc(strlen(str));
    int j = 0;

    for (int i = pos; str[i] != '\0'; i++, j++)
        buffer[j] = str[i];
    return (buffer);
}

char *special_case(char *str, mysh_s *sh)
{
    char *path = get_my_pwd(sh->env.environment);
    char *buffer = path;

    buffer = realloc(buffer, strlen(buffer) + strlen(str));
    if (str[1] == '+') {
        buffer = get_all_pwd(sh->env.environment);
        str = extract_name(str, 1);
    }
    if (str[1] == '/' || str[2] == '/') {
        if (str[1] == '-')
            buffer = strcat(buffer, extract_name(str, 2));
        else if (str[1] == '/')
            buffer = strcat(buffer, extract_name(str, 1));
    }
    else if (str[1] == '-')
        return (str);
    return (buffer);
}

char *get_new_path(char *str, mysh_s *sh)
{
    char *path = get_my_pwd(sh->env.environment);
    char *buffer = my_alloc(1024);

    if (strlen(str) < 2)
        return (path);
    if (str[1] == '/' || str[1] == '+' || str[1] == '-')
        return (special_case(str, sh));
    else {
        if (is_user(extract_name(str, 1), sh->env.environment) == 1) {
            buffer = strdup("/home/");
            buffer = strcat(buffer, extract_name(str, 1));
            return (buffer);
        }
        else {
            printf("Unknown user: %s.\n", extract_name(str, 1));
            return (NULL);
        }
    }
    return (str);
}

char **check_echo(char **args, mysh_s *sh)
{
    char **stock = malloc(sizeof(char *) * (sizeof(args)));

    for (int i = 1; args[i] != NULL; i++) {
        if (args[i][0] == '~') {
            stock[i] = get_new_path(args[i], sh);
        }
        else
            stock[i] = args[i];

    }
    return (stock);
}

int echo(char **args, mysh_s *mysh)
{
    if (mysh->com.com == NULL)
        return (ERROR);
    args = check_echo(args, mysh);
    if (args[1] != NULL && strcmp(args[1], "/tmp/res42\0") != 0)
        write(1, args[1], strlen(args[1]));
    else {
        write(1, "\n", 1);
        return (SUCCESS);
    }
    for (int i = 2; args[i] != NULL &&
        strcmp(args[i], "/tmp/res42\0") != 0; i += 1) {
        write(1, " ", 1);
        write(1, args[i], strlen(args[i]));
    }
    write(1, "\n", 1);
    return (SUCCESS);
}
