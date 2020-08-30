/*
** EPITECH PROJECT, 2019
** PSU_42sh_2018
** File description:
** get_signal_error
*/

#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <signal.h>
#include <string.h>
#include "minishell.h"
#include "lib.h"
#include <stdio.h>

int no_perm(char **tab)
{
    if (strlen(tab[0]) >= 2 && tab[0][0] == '.' && tab[0][1] == '/')
        return (1);
    if (strlen(tab[0]) >= 1 && tab[0][0] == '/')
        return (1);
    return (0);
}

void put_signal_error(int wstatus)
{
    int sig = 0;

    if (WIFSIGNALED(wstatus)) {
        if (WTERMSIG(wstatus) == 9)
            return;
        sig = WTERMSIG(wstatus);
        if (sig == SIGSEGV)
            puts("Segmentation fault");
        if (sig == SIGFPE)
            puts("Floating exception");
    }
}
