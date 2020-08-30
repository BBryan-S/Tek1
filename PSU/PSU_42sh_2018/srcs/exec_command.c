/*
** EPITECH PROJECT, 2018
** PSU_minishell2_2018
** File description:
** exec_command.c
*/

#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <signal.h>
#include <errno.h>
#include "minishell.h"
#include "lib.h"
#include <stdio.h>

char *my_shell_realloc(char *str, char *path)
{
    char *dest = my_alloc(my_strlen(str) + my_strlen(path) + 1);

    if (!dest)
        return (NULL);
    dest = my_strcat(dest, path);
    dest = my_strcat(dest, "/");
    dest = my_strcat(dest, str);
    return (dest);
}

int check_path(char *str)
{
    for (int a = 0; str[a]; a = a + 1) {
        if (str[a] == '/')
            return (SUCCESS);
    }
    return (FAILURE);
}

int exec(char **path, char **env, char **parser)
{
    int check = check_path(parser[0]);
    char *path_str;

    if (check == SUCCESS) {
        execve(parser[0], parser, env);
        return (FAILURE);
    }
    for (int a = 0; path[a]; a = a + 1) {
        path_str = my_shell_realloc(parser[0], path[a]);
        execve(path_str, parser, env);
    }
    return (FAILURE);
}

int my_execve(char **parser, char **path, char **env, char *arch)
{
    pid_t pid;
    int wstatus = 0;
    int a = 0;
    int type = get_type(parser, path, env);

    if (type == 0) {
        pid = fork();
        if (pid == 0) {
            exec(path, env, parser);
            a = -1;
        } else
            waitpid(pid, &wstatus, WUNTRACED | WCONTINUED);
    } else
        send_function(type, parser, path, env);
    put_signal_error(wstatus);
    if (errno == ENOEXEC) {
        printf("%s: Exec format error. Wrong Architecture.\n", parser[0]);
        *arch = 1;
    }
    return (a);
}

int exec_command(char **tab, char **path, char **env)
{
    char arch = 0;

    if (my_execve(tab, path, env, &arch) == FAILURE) {
        if (no_perm(tab) && !arch)
            printf("%s: Permission denied.\n", tab[0]);
        else if (!arch)
            printf("%s: Command not found.\n", tab[0]);
        kill(getpid(), SIGKILL);
    }
    return (SUCCESS);
}
