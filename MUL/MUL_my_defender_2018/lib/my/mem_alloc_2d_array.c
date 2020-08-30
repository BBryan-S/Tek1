/*
** EPITECH PROJECT, 2018
** mem_alloc_2d_array
** File description:
** mem_alloc_2d_array
*/

#include <stdlib.h>

char **mem_alloc_2d_array(int nb_rows, int nb_cols)
{
    char **arr = malloc(sizeof(char *) * nb_rows + 1);

    for (int i = 0; i < nb_rows; i = i + 1)
        arr[i] = malloc(sizeof(char) * nb_cols + 1);
    return (arr);
}
