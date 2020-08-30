/*
** EPITECH PROJECT, 2019
** 42sh
** File description:
** redirection
*/

#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <signal.h>
#include "minishell.h"
#include "lib.h"
#include <fcntl.h>
#include <stdio.h>
#include <string.h>

int get_targ(char **parser, char **targ)
{
    for (int i = 0; parser[i] != NULL; i++) {
        if (my_strcmp(parser[i], ">") == 0 || my_strcmp(parser[i], ">>") == 0 ||
            my_strcmp(parser[i], "<") == 0 || my_strcmp(parser[i], "<<") == 0) {
            if (parser[i + 1] != NULL && targ != NULL) {
                *targ = parser[i + 1];
                return (i);
            }
            else
                return (i);
        }
    }
    return (-1);
}

void get_content(char **parser, char **path, char **env, int file)
{
    int pos = get_targ(parser, NULL);
    int save = dup(1);
    mysh_s sh = init_struct(env);
    char *cmd = my_alloc(1);

    for (int i = 0; i < pos; i++) {
        cmd = realloc(cmd, strlen(cmd) + strlen(parser[i]) + 1);
        cmd = strcat(cmd, parser[i]);
        if (i + 1 < pos)
            cmd = strcat(cmd, " ");
    }
    dup2(file, 1);
    prepare_my_command(cmd, &sh);
    close(file);
    dup2(save, 1);
}

int create_file(int type, char **parser, char **path, char **env)
{
    int file;
    char *targ = my_alloc(1024);
    int pos = get_targ(parser, &targ);

    if (pos == -1)
        return (0);
    if (type == 1)
        file = open(targ, O_CREAT | O_WRONLY | O_APPEND, 0644);
    else
        file = open(targ, O_CREAT | O_TRUNC | O_WRONLY, 0644);
    get_content(parser, path, env, file);
    return (0);
}

int redirection(int type, char **parser, char **path, char **env)
{
    if (type == 3 || type == 1)
        return (create_file(type, parser, path, env));
    else if (type == 4)
        return (change_input(parser, path, env));
    else
        return (cat_input(parser, path, env));
    return (0);
}
