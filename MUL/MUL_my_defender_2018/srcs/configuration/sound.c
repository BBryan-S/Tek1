/*
** EPITECH PROJECT, 2019
** defender
** File description:
** sound
*/

#include <stdlib.h>
#include "../include/my.h"
#include "../include/defender.h"

void play_effect(game_t *gt, char *path)
{
    gt->timer.sound_time = sfClock_getElapsedTime(gt->timer.sound);
    gt->timer.time_s = gt->timer.sound_time.microseconds / 1000000.0;
    if (gt->timer.time_s < 1.0 && (my_strcmp(path, BOW) == 0 ||
        my_strcmp(path, M_CLIC) == 0))
        return;
    else if (my_strcmp(path, BOW) == 0 || my_strcmp(path, M_CLIC) == 0)
        sfClock_restart(gt->timer.sound);
    if (gt->audio.effet_enable == 1) {
        gt->audio.effect = sfMusic_createFromFile(path);
        sfMusic_setVolume(gt->audio.effect, 20.0);
        if (sfMusic_getStatus(gt->audio.effect) != 2)
            sfMusic_play(gt->audio.effect);
    }
}

void play_music(game_t *gt, char *path)
{
    if (gt->audio.music_enable == 1) {
        gt->audio.music = sfMusic_createFromFile(path);
        sfMusic_setLoop(gt->audio.music, sfTrue);
        sfMusic_setVolume(gt->audio.music, 30.0);
        sfMusic_play(gt->audio.music);
    }
}
