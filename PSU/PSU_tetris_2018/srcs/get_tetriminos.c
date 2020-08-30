/*
** EPITECH PROJECT, 2018
** PSU_tetris_2018
** File description:
** get_tetriminos.c
*/

#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include "tetris.h"
#include "lib.h"
#include "get_next_line.h"

char **tab_realloc(char **tab, char *str)
{
    char **dest;
    int a = 0;

    for (; tab[a] != NULL; a = a + 1);
    dest = malloc(sizeof(char *) * (a + 2));
    if (!dest)
        return (NULL);
    for (int b = 0; tab[b]; b = b + 1) {
        dest[b] = my_strdup(tab[b]);
    }
    my_free(tab);
    dest[a] = my_strdup(str);
    dest[a + 1] = NULL;
    return (dest);
}

int set_tetri_params(tetriminos_t *tetrimino, int fd)
{
    char *str = get_next_line(fd);
    char **tab;

    if (!str)
        return (84);
    tab = my_str_to_word_array(str, ' ');
    if (!tab)
        return (84);
    else if (!tab[1] || !tab[2]) {
        my_free(tab);
        return (-1);
    }
    tetrimino->x = my_getnbr(tab[0]);
    tetrimino->y = my_getnbr(tab[1]);
    tetrimino->color = my_getnbr(tab[2]);
    my_free(tab);
    free(str);
    return (0);
}

int fill_tetriminos_struct(char *filename, tetriminos_t *tetrimino)
{
    int fd = open(complete_fname(filename), O_RDONLY);
    char *str;

    tetrimino->x = -1;
    tetrimino->y = -1;
    tetrimino->color = -1;
    tetrimino->name = my_strdup(filename);
    tetrimino->tetrimino = NULL;
    if (set_tetri_params(tetrimino, fd) != 0)
        return (-1);
    tetrimino->tetrimino = malloc(sizeof(char *) * (1));
    tetrimino->tetrimino[0] = NULL;
    str = get_next_line(fd);
    for (int a = 0; str; a++) {
        tetrimino->tetrimino = tab_realloc(tetrimino->tetrimino, str);
        free(str);
        str = get_next_line(fd);
    }
    close(fd);
    return (0);
}

int set_tetriminos(tetris_t *tet, char **tab)
{
    int a = 0;

    for (int b = 0; tab[b]; b++) { 
        if (check_file(tab[b]) == 0)
            a++;
    }
    tet->tetriminos = malloc(sizeof(tetriminos_t) * (a));
    tet->nb_tetriminos = a;
    a = 0;
    for (int b = 0; tab[b]; b++) {
        if (check_file(tab[b]) == 0) {
            fill_tetriminos_struct(tab[b], &tet->tetriminos[a]);
            a++;
        }
    }
    my_free(tab);
    return (0);
}

int get_tetriminos(tetris_t *tet)
{
    DIR *dir = opendir("tetriminos");
    struct dirent *file = NULL;
    char **tab = malloc(sizeof(char *) * (2));

    if (!dir)
        return (84);
    file = readdir(dir);
    tab[0] = my_strdup(file->d_name);
    tab[1] = NULL;
    for (int a = 1; file != NULL; a = a + 1) {
        file = readdir(dir);
        if (file != NULL) {
            tab = tab_realloc(tab, file->d_name);
            tab[a + 1] = NULL;
        }
        if (!tab)
            return (84);
    }
    closedir(dir);
    return (set_tetriminos(tet, tab));
}