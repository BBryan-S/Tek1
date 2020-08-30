/*
** EPITECH PROJECT, 2018
** PSU_tetris_2018
** File description:
** tetris.h
*/

#ifndef _TETRIS_H_
#define _TETRIS_H_

typedef struct setting_s {
    int height;
    int width;
    int level;
    int left;
    int right;
    int turn;
    int drop;
    int quit;
    int pause;
    int next;
    int debug;
    int help;
} setting_t;

typedef struct tetriminos_s {
    char *name;
    char **tetrimino;
    int y;
    int x;
    int color;
} tetriminos_t;

typedef struct tetris_s {
    int (*com_list[11])();
    char small_command[11][7];
    char large_command[11][20];
    struct setting_s setting;
    struct tetriminos_s *tetriminos;
    int nb_tetriminos;
} tetris_t;

void set_command(tetris_t *tet);
void print_help(void);
void print_debug(tetris_t tet);
void my_free(char **tab);

tetris_t set_struct(void);

int display_help(char **arg, tetris_t *tet, int pos);
int change_level(char **arg, tetris_t *tet, int pos);
int change_left(char **arg, tetris_t *tet, int pos);
int change_right(char **arg, tetris_t *tet, int pos);
int change_turn(char **arg, tetris_t *tet, int pos);
int change_drop(char **arg, tetris_t *tet, int pos);
int change_quit(char **arg, tetris_t *tet, int pos);
int change_pause(char **arg, tetris_t *tet, int pos);
int change_size(char **arg, tetris_t *tet, int pos);
int change_next(char **arg, tetris_t *tet, int pos);
int change_debug(char **arg, tetris_t *tet, int pos);
int get_tetriminos(tetris_t *tet);
int check_file(char *str);

char *complete_fname(char *str);

#endif