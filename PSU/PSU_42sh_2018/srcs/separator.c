/*
** EPITECH PROJECT, 2018
** PSU_42sh_2018
** File description:
** separator.c
*/

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <signal.h>
#include "minishell.h"
#include "lib.h"
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

char *set_path_file(char *str, char *cmd)
{
    char *dest = my_alloc(strlen(cmd) + strlen(str) + 2);
    int mark = 0;
    int j = 0;

    for (; cmd[mark] && cmd[mark] != '>' && cmd[mark] != '<'; mark++);
    for (int i = 0; i < mark; i++) {
        dest[i] = cmd[i];
    }
    dest = strcat(dest, " ");
    dest = strcat(dest, str);
    dest = strcat(dest, " ");
    j = strlen(dest);
    for (int i = mark; cmd[i] != '\0'; i++, j++)
        dest[j] = cmd[i];
    return (dest);
}

int separator_pipe(char *command, mysh_s *mysh)
{
    char **tab = my_str_to_word_array(command, '|');
    char *str = NULL;
    int c = 0;
    int i = 0;

    if (!tab[1]) {
        return (prepare_my_command(command, mysh));
    } else {
        open("/tmp/res42", O_CREAT | O_TRUNC | O_WRONLY, 0644);
        for (; tab[i + 1] != NULL; i++) {
            str = get_pipe_buff(tab[i], mysh, &c);
            tab[i + 1] = set_path_file(str, tab[i + 1]);
        }
        c = prepare_my_command(tab[i], mysh);
    }
    return (c);
}

int separator(char *command, mysh_s *mysh)
{
    char **tab = my_parser(command, "&&");
    char **tab2;
    int c = FAILURE;

    tab = remove_space(tab);
    for (int a = 0; tab[a]; a++) {
        c = FAILURE;
        tab2 = my_parser(tab[a], "||");
        tab2 = remove_space(tab2);
        for (int b = 0; tab2[b] && c == FAILURE; b++) {
            c = separator_pipe(tab2[b], mysh);
        }
        if (c != SUCCESS) {
            return (c);
        }
    }
    return (SUCCESS);
}
