/*
** EPITECH PROJECT, 2018
** MUL_my_runner_2018
** File description:
** struct_create.c
*/

#include <stdlib.h>
#include "lib.h"
#include "my_runner.h"

void set_vector(sfVector2f *position, sfVector2f pos1, sfVector2f pos2)
{
    position[0] = pos1;
    position[1] = pos2;
}

void position_init(my_runner *run)
{
    sfVector2f pos1 = {0, 0};
    sfVector2f pos2 = {1998, 0};

    run->back1->position = malloc(sizeof(sfVector2f) * (2));
    run->back2->position = malloc(sizeof(sfVector2f) * (2));
    run->back3->position = malloc(sizeof(sfVector2f) * (2));
    run->back4->position = malloc(sizeof(sfVector2f) * (2));
    set_vector(run->back1->position, pos1, pos2);
    set_vector(run->back2->position, pos1, pos2);
    set_vector(run->back3->position, pos1, pos2);
    set_vector(run->back4->position, pos1, pos2);
    sfSprite_setPosition(run->back1->back, pos2);
    sfSprite_setPosition(run->back2->back, pos2);
    sfSprite_setPosition(run->back3->back, pos2);
    sfSprite_setPosition(run->back4->back, pos2);
}

my_runner *struct_create(void)
{
    my_runner *run = malloc(sizeof(my_runner));

    run->window = create_my_window("MY_RUNNER", 1920, 1080, 32);
    run->back1 = malloc(sizeof(back_s));
    run->back2 = malloc(sizeof(back_s));
    run->back3 = malloc(sizeof(back_s));
    run->back4 = malloc(sizeof(back_s));
    run->back1->back = sprite_from_file("Picture/2_1.png", 0.7, 0.5);
    run->back2->back = sprite_from_file("Picture/2_2.png", 0.7, 0.5);
    run->back3->back = sprite_from_file("Picture/2_3.png", 0.7, 0.5);
    run->back4->back = sprite_from_file("Picture/2_4.png", 0.8, 0.5);
    position_init(run);
    run->clock = sfClock_create();
    run->seconds = 0;
    return (run);
}