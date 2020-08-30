/*
** EPITECH PROJECT, 2018
** lib.h
** File description:
** my
*/

#ifndef _MY_H_
#define _MY_H_

void my_putchar(char);
int my_put_nbr(int);
int my_putstr(char const *);
int my_strlen(char const *);
int my_getnbr(char const *);
char *my_strcpy(char *, char const *);
char *my_revstr(char *);
char *my_alloc(int);
int my_strcmp(char const *, char const *);
char *my_strcat(char *, char const *);
char *my_strdup(char const *);
char **my_str_to_word_array(char const *);
int my_show_word_array(char **);
int my_stringlen(char const *);
char *alloc_line(int);
int check_char(char const);
int my_wordlen(char const *, int);
int nb_word(char const *);
char **my_parser(char const *, char const);

#endif
