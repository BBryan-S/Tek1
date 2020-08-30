/*
** EPITECH PROJECT, 2018
** PSU_minishell2_2018
** File description:
** env_pwd.c
*/

#include "lib.h"
#include "minishell.h"

char **set_cd_env(void)
{
    char **dest = malloc(sizeof(char *) * (4));

    dest[0] = my_strdup("setenv");
    dest[1] = my_strdup("PWD");
    dest[3] = NULL;
    return (dest);
}

void env_pwd(char **env)
{
    int len = 200;
    char *str = my_alloc(100);
    char **cd_env = set_cd_env();

    str = getcwd(str, 100);
    for (; str == NULL; len = len * 2) {
        free(str);
        str = my_alloc(len);
        str = getcwd(str, len);
    }
    cd_env[2] = my_strdup(str);
    free(str);
    env = set_env(cd_env, env);
    my_free(cd_env);
}
