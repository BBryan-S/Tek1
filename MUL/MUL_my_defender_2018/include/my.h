/*
** EPITECH PROJECT, 2018
** my.h
** File description:
** prototypes
*/

#ifndef _MY_H_
#define _MY_H_

void my_putchar(char);
int my_put_nbr_base(int, char const *, int);
int my_put_nbr(int);
int my_putstr(char const *);
char *my_strcat(char *, char *);
int my_strcmp(char const *, char const *);
char *my_strcpy(char *, char const *);
char *my_strdup(char const *);
int my_strlen(char const *);
char *my_strlowcase(char *);
char *my_strncat(char *, char const *, int);
int my_strncmp(char const *, char const *, int, int);
char *my_strncpy(char *, char const *, int, int);
int isleter2(char);
int count_str(char const *);
char **my_str_to_word_array(char const *);
char *my_strupcase(char *);
int is_alpha(char);
int is_num(char);
int my_getnbr(char const *str);
char *my_alloc(int);
char *load_file_in_mem(char const *);
int my_printf(char *, ...);
char *my_revstr(char *);
char *my_itoa(int);
char **str_to_array(char *, char);
char **push_arr(char **, char *);
char **pull_arr(char **, char *);
char *push_string(char *, char, int);
char *pull_string(char *, char);
#endif
