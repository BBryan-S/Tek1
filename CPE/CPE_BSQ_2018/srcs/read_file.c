/*
** EPITECH PROJECT, 2018
** main.c
** File description:
** main
*/

#include "../include/my.h"
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>

char *read_file(char *filepath, int *len)
{
    int fd = open(filepath, O_RDONLY);
    int a;
    struct stat *filestat = malloc(sizeof(struct stat));
    char *buffer;
    char c;

    stat(filepath, filestat);
    buffer = my_alloc(filestat->st_size);
    read(fd, &c, 1);
    for (a = 1; c && c != '\n'; a = a + 1)
        read(fd, &c, 1);
    read(fd, buffer, filestat->st_size);
    *len = filestat->st_size - a;
    free(filestat);
    close(fd);
    return (buffer);
}
