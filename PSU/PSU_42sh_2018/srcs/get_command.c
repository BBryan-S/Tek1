/*
** EPITECH PROJECT, 2018
** PSU_42sh_2018
** File description:
** get_command.c
*/

#include <stdlib.h>
#include "lib.h"
#include "get_next_line.h"
#include "minishell.h"
#include <string.h>

int check_com_list(char **tab, mysh_s * mysh)
{
    int a = 0;
    int cmp = FAILURE;
    int c = FAILURE;

    while (a < 7 && cmp != SUCCESS) {
        cmp = my_strcmp(tab[0], mysh->fct.list[a]);
        if (cmp != SUCCESS)
            a = a + 1;
    }
    if (a != 7)
        c = (*mysh->fct.com_list[a]) (tab, mysh);
    return (c);
}

char *change_path(char **dest, int i)
{
    char *buffer = my_alloc(1);
    int a = 0;

    for (int j = i + 1; dest[j] != NULL; j++) {
        buffer = realloc(buffer, strlen(buffer) + strlen(dest[j]) + 1);
        buffer = strcat(buffer, dest[j]);
        buffer = strcat(buffer, " ");
    }
    a = strlen(buffer);
    buffer = realloc(buffer, strlen(buffer) + strlen(dest[i]));
    for (int b = 1; dest[i][b]; b++)
        buffer[a++] = dest[i][b];
    buffer[a] = '\0';
    return (buffer);
}

char *check_order_cmd(char *str)
{
    char **dest = my_str_to_word_array(str, ' ');

    for (int i = 0; dest[i] != NULL; i++) {
        if (strncmp(dest[i], "</", 2) == 0)
            return (change_path(dest, i));
    }
    return (str);
}

int prepare_my_command(char *str, mysh_s *mysh)
{
    char **tab;
    int c = 0;

    str = check_order_cmd(str);
    tab = parse_quote(str);
    if (!tab || tab[0][0] == '\0')
        return (FAILURE);
    c = check_com_list(tab, mysh);
    if (c != FAILURE) {
        return (c);
    }
    return (exec_command(tab, mysh->env.path, mysh->env.environment));
}

int get_command(mysh_s *mysh)
{
    int c = 0;

    mysh->com.com = get_next_line(0);
    if (!mysh->com.com)
        return (ERROR);
    else if (mysh->com.com[0] == '\0')
        return (SUCCESS);
    mysh->com.parser = my_str_to_word_array(mysh->com.com, ';');
    mysh->com.parser = remove_space(mysh->com.parser);
    if (!mysh->com.parser)
        return (ERROR);
    for (int a = 0; mysh->com.parser[a] != NULL; a++) {
        c = separator(mysh->com.parser[a], mysh);
        if (c == EXIT || c == ERROR)
            return (c);
    }
    return (SUCCESS);
}
