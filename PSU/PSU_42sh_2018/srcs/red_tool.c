/*
** EPITECH PROJECT, 2019
** 42
** File description:
** tool
*/

#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <signal.h>
#include "minishell.h"
#include "get_next_line.h"
#include "lib.h"
#include <fcntl.h>
#include <stdio.h>
#include <string.h>

char *get_quote_cont(int *i, char *str, char quote)
{
    int mark = *i + 1;
    char *buffer;

    for (; str[mark] != '\0' && str[mark] != quote; mark++);
    if (str[mark] != quote) {
        printf("Unmatched '%c'.\n", quote);
        return (NULL);
    }
    buffer = my_alloc(mark - *i + 5);
    *i = *i + 1;
    for (int j = 0; *i != mark; j++, *i = *i + 1)
        buffer[j] = str[*i];
    if (str[*i] == quote)
        *i = *i + 1;
    return (buffer);
}

char *get_space_cont(int *i, char *str)
{
    int mark = *i - 1;
    char *buffer;

    for (; mark > 0 && str[mark] != ' ' && str[mark] != '\''
        && str[mark] != '"'; mark--);
    buffer = my_alloc(*i - mark + 3);
    if (mark >= 0 && (str[mark] == ' ' || str[mark] == '\'' ||
        str[mark] == '"'))
        mark++;
    for (int j = 0; mark >= 0 && mark < *i; mark++, j++)
        buffer[j] = str[mark];
    for (; str[*i] != '\0' && str[*i + 1] != '\0' && str[*i] == ' ' &&
        str[*i + 1] == ' '; *i = *i + 1);
    buffer = rem_space(buffer);
    return (buffer);
}

char *get_last_cont(char *str, int i)
{
    int mark = i;
    char *buffer;

    for (; mark > 0 && str[mark] != ' ' && str[mark] != '\'' &&
        str[mark] != '"'; mark--);
    buffer = my_alloc(i - mark + 1);
    for (int j = 0; str[mark] != '\0'; j++, mark++)
        buffer[j] = str[mark];
    buffer = rem_space(buffer);
    buffer[strlen(buffer)] = '\0';
    return (buffer);
}

char **parse_quote(char *str)
{
    char **tab = malloc(sizeof(char *) * 30);
    char *buffer = NULL;
    int j = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        if ((str[i] == 34) || (str[i] == '\''))
            buffer = get_quote_cont(&i, str, str[i]);
        else if (str[i] == ' ')
            buffer = get_space_cont(&i, str);
        else if (str[i + 1] == '\0')
            buffer = get_last_cont(str, i);
        if (buffer != NULL && strlen(buffer) > 0) {
            tab[j] = my_strdup(buffer);
            j++;
            buffer = NULL;
        }
    }
    tab[j] = NULL;
    return (tab);
}

char *get_pipe_buff(char *cmd, mysh_s *sh, int *c)
{
    int save = dup(1);
    char *path = strdup("/tmp/res42\0");
    char *out = strdup("/tmp/out42\0");
    int fd = open(path, O_CREAT | O_WRONLY, 0644);
    int output = open(out, O_CREAT | O_TRUNC | O_WRONLY, 0644);

    dup2(output, 1);
    *c = prepare_my_command(cmd, sh);
    dup2(save, 1);
    dup2(fd, 1);
    prepare_my_command("cat /tmp/out42", sh);
    dup2(save, 1);
    close(fd);
    return (path);
}
