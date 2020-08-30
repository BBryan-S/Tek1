/*
** EPITECH PROJECT, 2018
** CPE_matchstick_2018
** File description:
** ai_turn.c
*/

#include "matchstick.h"
#include "lib.h"

void remove_one_matches(char **map, int *line, int *matches)
{
    for (int y = 0; map[y] && *matches == 0; y = y + 1) {
        if (l_left(map[y]) >= 1) {
            *matches = 1;
            *line = y;
        }
    }
}

void get_ai_params(char **map, int nb_matches, int *line, int *matches)
{
    int bigl_left = 0;
    int m_left = matches_left(map, &bigl_left);

    if (m_left <= nb_matches + 1 && m_left > 1) {
        if (l_left(map[bigl_left]) == m_left) {
            *line = bigl_left;
            *matches = m_left - 1;
        } else if (l_left(map[bigl_left]) == m_left - 1) {
            *line = bigl_left;
            *matches = m_left - 1;
        } else
            remove_one_matches(map, line, matches);
    } else
        remove_one_matches(map, line, matches);
}

int ai_turn(char **map, int nb_matches)
{
    int line = 0;
    int matches = 0;

    my_show_word_array(map);
    my_putstr("\nAI's turn...\n");
    get_ai_params(map, nb_matches, &line, &matches);
    remove_matches(map, line, matches, 1);
    return (check_victory(map, 1));
}