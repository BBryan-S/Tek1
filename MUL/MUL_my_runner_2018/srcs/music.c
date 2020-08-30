/*
** EPITECH PROJECT, 2018
** MUL_my_runner_2018
** File description:
** music.c
*/

#include <SFML/Audio/Export.h>
#include <SFML/Audio/SoundStatus.h>
#include <SFML/Audio/Types.h>
#include <SFML/Audio.h>
#include <SFML/System/InputStream.h>
#include <SFML/System/Time.h>
#include <SFML/System/Vector3.h>
#include <stddef.h>

sfMusic *play_music(void)
{
    sfMusic *music = sfMusic_createFromFile("Audio/music.ogg");

    sfMusic_setLoop(music, 1);
    sfMusic_play(music);
    return (music);
}
