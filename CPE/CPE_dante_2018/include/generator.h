/*
** EPITECH PROJECT, 2018
** Visual Studio Live Share (Workspace)
** File description:
** generator.h
*/

#ifndef _GENERATOR_H_
#define _GENERATOR_H_

typedef enum {
    ERROR = 84,
    SUCCESS = 0,
    FAILURE = -1,
    PERFECT = 10,
    IMPERFECT = 11,
    WALL = 0,
    FREE = 1,
    PATH = 2,
} my_enum_t;

typedef struct gen_s {
    int x;
    int y;
    int maze_status;
    int **map;
} gen_t;

int get_info(int , char **, gen_t *);
void display(gen_t *);
void generator(gen_t *);
void set_wall(gen_t *);
int size_ok(int, int, gen_t *);
void make_branch(gen_t *);
int is_ending (gen_t *);
int no_path(int, int, gen_t *);
int check_cell(gen_t *, int, int);
#endif
