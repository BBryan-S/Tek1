/*
** EPITECH PROJECT, 2019
** defender
** File description:
** misc
*/

#include "../include/my.h"
#include "../include/defender.h"
#include <stdlib.h>

int next_compare(char *str)
{
    if (my_strncmp(str, "Bruitage", 0, 5) == 0)
        return (8);
    else if (my_strncmp(str, "Argen", 0, 5) == 0)
        return (9);
    else
        return (10);
}

int next_menu(game_t *gt)
{
    switch (display_menu_start(gt)) {
    case 1:
        menu_option(gt);
        break;
    case 2:
        menu_aide(gt);
        break;
    case 3:
        display_score_menu(gt);
        break;
    }
}
