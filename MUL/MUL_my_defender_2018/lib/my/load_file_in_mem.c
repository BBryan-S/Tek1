/*
** EPITECH PROJECT, 2018
** load_file_in_mem
** File description:
** load file in mem
*/

#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>

char *my_alloc(int size);

char *load_file_in_mem(char const *filepath)
{
    struct stat st;
    char *dest;
    int fd = open(filepath, O_RDONLY);

    if (fd == -1)
        exit (84);
    stat(filepath, &st);
    dest = my_alloc(st.st_size);
    read(fd, dest, st.st_size);
    return (dest);
}
