/*
** EPITECH PROJECT, 2018
** fs_get_number_from_first_line
** File description:
** fs_get_number_from_first_line
*/

#include "../../include/my.h"
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>

int get_nbr_fs(char const *path, int i)
{
    int fd = open(path, O_RDONLY);
    char *res = malloc(sizeof(char) * i + 1);

    read(fd, res, i);
    return (my_getnbr(res));
}

int fs_get_number_from_first_line(char const *filepath)
{
    int fd = open(filepath, O_RDONLY);
    char line[2];
    int i = 0;
    int res = 0;

    if (fd == -1)
        return (-1);
    while (read(fd, line, 1) != 0 && line[0] != '\n')
        i = i + 1;
    close(fd);
    res = get_nbr_fs(filepath, i);
    if (res == 0)
        return (-1);
    return (res);
}
