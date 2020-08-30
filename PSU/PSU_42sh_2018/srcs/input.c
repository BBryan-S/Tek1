/*
** EPITECH PROJECT, 2019
** 42
** File description:
** input redirection
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

char *read_file(char *target)
{
    FILE *file = fopen(target, "r");
    char *fichier = malloc(sizeof(char *) * 1);
    char *buffer;
    size_t size = 0;

    while (getline(&buffer, &size, file) != -1) {
        fichier = realloc(fichier, strlen(fichier) + strlen(buffer));
        strcat(fichier, buffer);
    }
    return (fichier);
}

void execute_file(char **parser, char **path, char **env)
{
    mysh_s sh = init_struct(env);
    char *cmd = my_alloc(1);

    for (int i = 0; parser[i] != NULL; i++) {
        cmd = realloc(cmd, strlen(cmd) + strlen(parser[i]) + 5);
        cmd = strcat(cmd, parser[i]);
        if (parser[i + 1] != NULL)
            cmd = strcat(cmd, " ");
    }
    cmd[strlen(cmd)] = '\0';
    prepare_my_command(cmd, &sh);
}

int change_input(char **parser, char **path, char **env)
{
    char *targ = my_alloc(1024);
    int pos = get_targ(parser, &targ);
    char **stoc = malloc(sizeof(char *) * (pos + 2));

    targ[strlen(targ)] = '\0';
    if (pos == -1)
        return (0);
    for (int i = 0; i < pos; i++)
        stoc[i] = parser[i];
    stoc[pos] = targ;
    stoc[pos + 1] = NULL;
    execute_file(stoc, path, env);
    return (0);
}

char *cat_it(char *targ)
{
    char *buffer = "\0";
    char *stoc = malloc(sizeof(char) * 1);
    size_t size = 0;

    while (strcmp(targ, buffer) != 0) {
        printf("? ");
        getline(&buffer, &size, stdin);
        stoc = realloc(stoc, strlen(stoc) + strlen(buffer));
        buffer[strlen(buffer) - 1] = '\0';
        if (my_strcmp(targ, buffer) != 0) {
            strcat(stoc, buffer);
            strcat(stoc, "\n");
        }
    }
    stoc[strlen(stoc)] = '\0';
    return (stoc);
}

int cat_input(char **parser, char **path, char **env)
{
    char *targ;
    int pos = get_targ(parser, &targ);
    char *buffer;
    char **stoc = malloc(sizeof(char *) * (pos + 1));
    int fd = open("/tmp/res42", O_CREAT | O_TRUNC | O_WRONLY, 0644);

    if (pos == -1)
        return (0);
    for (int i = 0; i < pos; i++)
        stoc[i] = parser[i];
    buffer = cat_it(targ);
    write(fd, buffer, strlen(buffer));
    stoc[pos] = "/tmp/res42\0";
    execute_file(stoc, path, env);
    close(fd);
    return (0);
}
