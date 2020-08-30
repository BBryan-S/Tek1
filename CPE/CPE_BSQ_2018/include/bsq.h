/*
** EPITECH PROJECT, 2018
** bsq.h
** File description:
** bsq
*/

#ifndef _BSQ_H_
#define _BSQ_H_

char *read_file(char *, int *);
char **parsing_buffer(char *);
void find_biggest_square(char *, int, int, int);
int **get_square(int **, int, int);
int get_nb_line(char *);
int get_line_len(char *);

#endif
