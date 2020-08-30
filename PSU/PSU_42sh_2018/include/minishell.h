/*
** EPITECH PROJECT, 2018
** PSU_minishell2_2018
** File description:
** minishell.h
*/

#ifndef _MY_SH_
#define _MY_SH_

#include <unistd.h>
#include <stdlib.h>

typedef enum
{
    SUCCESS = 0,
    FAILURE = -1,
    ERROR = 84,
    EXIT = -5,
} my_enum_t;

typedef struct function_t
{
    int (*com_list[7])();
    char list[7][9];
} function_s;

typedef struct environment_t
{
    char **environment;
    char **path;
} environment_s;

typedef struct command_t
{
    char **pipe_parser;
    char **parser;
    char *com;
} command_s;

typedef struct mysh_t
{
    function_s fct;
    environment_s env;
    command_s com;
} mysh_s;


void command_list(function_s *fct);
void my_free(char **tab);
void env_pwd(char **env);

mysh_s init_struct(char **env);

int get_command(mysh_s *mysh);
int my_display_env(char **tab, mysh_s *mysh);
int my_setenv(char **tab, mysh_s *mysh);
int my_unsetenv(char **tab, mysh_s *mysh);
int my_cd(char **tab, mysh_s *mysh);
int my_exit(char **tab, mysh_s *mysh);
int check_alpha(char *s);
int my_strcompare(char const *str, char const *cmp);
int exec_command(char **tab, char **path, char **env);
int get_type(char **, char **, char **);
int send_function(int, char **, char **, char **);
int separator(char *command, mysh_s *mysh);
int redirection(int, char **, char **, char **);
int prepare_my_command(char *str, mysh_s *mysh);
int exec(char **, char **, char **);
int echo(char **args, mysh_s *mysh);
int is_dir(char *path);
int is_user(char *str, char **env);
char **remove_space(char **tab);
char **set_env(char **tab, char **env);
char **unset_env(char **tab, char **env);
char **my_parser(char const *str, char *c);

char *get_pipe_buff(char *, mysh_s *, int *);
int change_input(char **, char **, char **);
int cat_input(char **, char **, char **);
int get_targ(char **, char **);
char **parse_quote(char *);
char *rem_space(char *);
char *get_name(mysh_s *);
char *get_my_pwd(char **tab);
char *get_all_pwd(char **env);
char *extract_name(char *str, int pos);
void put_signal_error(int wstatus);
int no_perm(char **);
int my_ls(char **, mysh_s *);

#endif
