/*
** EPITECH PROJECT, 2019
** tool
** File description:
** tool
*/

#include <stdlib.h>
#include "../include/my.h"
#include "../include/defender.h"

char *next_description(char *str, int index, int prix, game_t *gt)
{
    str = my_strcat(str, "Bonus atq : ");
    str = my_strcat(str, my_itoa(gt->info.tower[index].b_atq));
    str = my_strcat(str, " %  -<  ");
    str = my_strcat(str, my_itoa(gt->info.tower[index].b_atq * 3));
    str = my_strcat(str, " %\n\nBonus vda : ");
    str = my_strcat(str, my_itoa(gt->info.tower[index].b_vda));
    str = my_strcat(str, " %  -<  ");
    str = my_strcat(str, my_itoa(gt->info.tower[index].b_vda * 2));
    str = my_strcat(str, " %\n");
    return (str);
}
