/*
** EPITECH PROJECT, 2018
** my_sokoban.h
** File description:
** my_sokoban
*/

#ifndef _MY_SOKOBAN_H_
#define _MY_SOKOBAN_H_

char *read_file(char *);
int display_usage(void);
int check_map(char **);
int my_game(char **);
void set_map(char **, char **);
char **map_dup(char **);
void print_map(char **);
int search_char(char *, char);
int get_position(char **, int *, int *);
void move_up(char **, char **, int, int);
void move_down(char **, char **, int, int);
void move_left(char **, char **, int, int);
void move_right(char **, char **, int, int);

#endif