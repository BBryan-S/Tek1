/*
** EPITECH PROJECT, 2018
** CPE_matchstick_bootstrap_2018
** File description:
** game.c
*/

#include "matchstick.h"
#include "lib.h"

int check_line_victory(char *str)
{
    for (int x = 1; str[x]; x = x + 1) {
        if (str[x] == '|')
            return (1);
    }
    return (0);
}

int check_victory(char **map, int player)
{
    for (int y = 1; map[y]; y = y + 1) {
        if (check_line_victory(map[y]) == 1)
            return (0);
    }
    my_show_word_array(map);
    if (player == 2)
        my_putstr("You lost, too bad...\n");
    else
        my_putstr("I lost... snif... but I'll get you next time!!\n");
    return (player);
}

int game(char **map, int nb_line, int nb_matches)
{
    int result;

    while (1) {
        result = player_turn(map, nb_line, nb_matches);
        if (result != 0)
            return (result);
        if (ai_turn(map, nb_matches) == 1)
            return (1);
    }
    return (0);
}