/*
** EPITECH PROJECT, 2018
** Lib
** File description:
** lib.h
*/


#ifndef _LIB_H_
#define _LIB_H_

void my_putchar(char);
char *my_strcpy(char *, char const *);
char *my_revstr(char *);
char *my_alloc(int);
char *my_strcat(char *, char const *);
char *my_strdup(char const *);
char **my_str_to_word_array(char const *, char);
char *alloc_line(int);
int my_put_nbr(int);
int my_put_nbr_base(unsigned int, char const *);
int my_putstr(char const *);
int my_strlen(char const *);
int my_getnbr(char const *);
int my_strcmp(char const *, char const *);
int my_show_word_array(char **);
int my_stringlen(char const *);
int check_char(char *, int *);
int my_wordlen(char const *, int);
int nb_word(char const *);
int sum_stdarg(int, int, ...);
int disp_stdarg(char *, ...);
int my_printf(char *, ...);
int prepare_my_putstr();
int prepare_my_putchar();
int prepare_my_put_nbr();
int prepare_my_put_octal();
int prepare_my_put_binnbr();
int prepare_my_put_min_hexanbr();
int prepare_my_put_maj_hexanbr();
int prepare_my_put_pointer();
int prepare_my_put_unsignednbr();
int prepare_my_put_percent();
int prepare_my_put_shortnbr();
int prepare_my_put_longnbr();
int flags_ss();

#endif
