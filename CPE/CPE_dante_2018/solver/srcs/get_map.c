/*
** EPITECH PROJECT, 2018
** CPE_dante_2018
** File description:
** get_map.c
*/

#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "my.h"
#include "solver.h"

int *get_int_line(char *str, int len)
{
    int *line = malloc(sizeof(int) * (len));

    for (int a = 0; str[a]; a++) {
        if (str[a] == 'X')
            line[a] = WALL;
        else
            line[a] = EMPTY;
    }
    return (line);
}

void get_int_map(solver_t *solv)
{
    int y = 0;
    int x = my_strlen(solv->tab[0]);

    for (; solv->tab[y]; y = y + 1);
    solv->map = malloc(sizeof(int *) * (y));
    for (int a = 0; solv->tab[a]; a++)
        solv->map[a] = get_int_line(solv->tab[a], x);
    solv->xmax = x - 1;
    solv->ymax = y - 1;
}

int check_line_map(char *str)
{
    for (int a = 0; str[a]; a++) {
        if (str[a] != 'X' && str[a] != '*')
            return (FAILURE);
    }
    return (SUCCESS);
}

int check_map(char **map)
{
    int len = my_strlen(map[0]);

    for (int a = 0; map[a]; a++) {
        if (check_line_map(map[a]) == FAILURE)
            return (FAILURE);
        else if (my_strlen(map[a]) != len)
            return (FAILURE);
    }
    return (SUCCESS);
}

char **get_map(char *filepath)
{
    int fd = open(filepath, O_RDONLY);
    struct stat filestat;
    char *str;
    char **tab;

    if (fd == -1)
        return (NULL);
    stat(filepath, &filestat);
    str = my_alloc(filestat.st_size);
    if (read(fd, str, filestat.st_size) == 0)
        return (NULL);
    close(fd);
    tab = my_str_to_word_array(str, '\n');
    free(str);
    if (check_map(tab) == FAILURE)
        return (NULL);
    return (tab);
}