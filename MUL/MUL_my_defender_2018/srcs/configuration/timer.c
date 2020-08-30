/*
** EPITECH PROJECT, 2019
** defender
** File description:
** timer
*/

#include <stdlib.h>
#include "../include/my.h"
#include "../include/defender.h"

void prepare_timer(timergame_t *timer)
{
    timer->main_time = sfClock_getElapsedTime(timer->main_clock);
    timer->mv_time = sfClock_getElapsedTime(timer->mvt);
    timer->anim_time = sfClock_getElapsedTime(timer->anim);
    timer->second = timer->main_time.microseconds / 1000000.0;
    timer->mv_s = timer->mv_time.microseconds / 1000000.0;
    timer->ani_s = timer->anim_time.microseconds / 1000000.0;
}

void configure_timer(timergame_t *timer)
{
    timer->main_clock = sfClock_create();
    timer->mvt = sfClock_create();
    timer->anim = sfClock_create();
    timer->sound = sfClock_create();
}
