/*
** EPITECH PROJECT, 2018
** CPE_matchstick_bootstrap_2018
** File description:
** player_turn.c
*/

#include "matchstick.h"
#include "lib.h"

void remove_matches(char **map, int line, int matches, int player)
{
    int x = my_strlen(map[line]);

    for (x = x - 1; map[line][x] != '|'; x = x - 1);
    for (int a = 0; a < matches; a = a + 1) {
        map[line][x] = ' ';
        x = x - 1;
    }
    if (player == 2)
        my_putstr("Player");
    else
        my_putstr("AI");
    my_putstr(" removed ");
    my_put_nbr(matches);
    my_putstr(" match(es) from line ");
    my_put_nbr(line);
    my_putchar('\n');
}

int player_turn(char **map, int nb_line, int nb_matches)
{
    int line = -1;
    int matches = -1;

    my_show_word_array(map);
    my_putstr("\nYour turn:\n");
    while (line == -1 || matches == -1) {
        line = get_line(nb_line);
        if (line == -2)
            return (-1);
        matches = get_matches(map, line, nb_matches);
        if (matches == -2)
            return (-1);
    }
    remove_matches(map, line, matches, 2);
    return (check_victory(map, 2));
}