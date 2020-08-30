/*
** EPITECH PROJECT, 2018
** CPE_dante_2018
** File description:
** solver.h
*/

#ifndef _SOLVER_H_
#define _SOLVER_H_

typedef enum {
    ERROR = 84,
    SUCCESS = 0,
    FAILURE = -1,
    WALL = -1,
    BLOCKED = -2,
    EMPTY = 0,
    NSOLUTION = -5,
} my_enum;

typedef struct solver_s {
    char **tab;
    int **map;
    int ymax;
    int xmax;
    int visit;
    int y;
    int x;
} solver_t;

char **get_map(char *filepath);

int search_solution(solver_t solv);

void get_int_map(solver_t *solv);
void search_visited(solver_t *solv, int visit);
void set_solution(solver_t solv);
void my_free(char **tab);
void show_my_tab(char **map);

#endif