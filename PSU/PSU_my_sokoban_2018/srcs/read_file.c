/*
** EPITECH PROJECT, 2018
** read_file.c
** File description:
** read_file
*/

#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include "../include/lib.h"

char *read_file(char *filepath)
{
    int fd = open(filepath, O_RDONLY);
    struct stat filestat;
    char *str;

    if (fd == -1)
        return (NULL);
    stat(filepath, &filestat);
    str = my_alloc(filestat.st_size);
    if (!str)
        return (NULL);
    if (read(fd, str, filestat.st_size) < 1)
        return (NULL);
    close(fd);
    return (str);
}