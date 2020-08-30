/*
** EPITECH PROJECT, 2018
** CPE_matchstick_bootstrap_2018
** File description:
** matchstick.h
*/

#ifndef _MATCH_H_
#define _MATCH_H_

char **create_map(int nb_line);
int game(char **map, int nb_line, int nb_matches);
int player_turn(char **map, int nb_line, int nb_matches);
int get_line(int nb_line);
int get_matches(char **map, int line, int nb_matches);
void remove_matches(char **map, int line, int matches, int player);
int check_victory(char **map, int player);
int matches_left(char **map, int *bigl_left);
int l_left(char *str);
int ai_turn(char **map, int nb_matches);

#endif