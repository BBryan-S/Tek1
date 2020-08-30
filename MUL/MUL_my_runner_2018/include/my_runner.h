/*
** EPITECH PROJECT, 2018
** MUL_my_runner_2018
** File description:
** my_runner.h
*/

#ifndef _RUNNER_H_
#define _RUNNER_H_

#include <SFML/Graphics.h>
#include <SFML/Graphics/RenderWindow.h>
#include <SFML/Graphics/Texture.h>
#include <SFML/Graphics/Sprite.h>
#include <SFML/Audio/Export.h>
#include <SFML/Audio/SoundStatus.h>
#include <SFML/Audio/Types.h>
#include <SFML/Audio.h>
#include <SFML/System/InputStream.h>
#include <SFML/System/Time.h>
#include <SFML/System/Vector3.h>
#include <stddef.h>

typedef struct background_s
{
     sfSprite *back;
     sfVector2f *position;
} back_s;

typedef struct my_player_s
{
     sfMusic *jump_sound;
     sfSprite *player;
     sfSprite *player_jump;
     sfIntRect player_rect;
     sfVector2f position;
     sfClock *clock;
     sfTime time;
     float seconds;
     int jump;
} my_player;

typedef struct my_obstacle_s
{
     sfSprite *obstacle;
     sfVector2f *position;
} my_obstacle;

typedef struct my_runner_s
{
     sfRenderWindow *window;
     struct background_s *back1;
     struct background_s *back2;
     struct background_s *back3;
     struct background_s *back4;
     struct my_obstacle_s *obstacle;
     sfMusic *music;
     sfClock *clock;
     sfTime time;
     float seconds;
     sfEvent event;
} my_runner;

my_runner *struct_create();
void set_vector(sfVector2f *, sfVector2f, sfVector2f);
void my_display(my_runner *run, my_player *player);
void my_display_jump(my_runner *run, my_player *player);
void my_event(my_runner *run, my_player *player);
my_player *player_init();
void set_player_position(my_player *player);
void jump_player(my_runner *run, my_player *player);
void move_back(my_runner *run);
int display_usage(int ac);
int my_cmp(char *str1, char *str2);
sfMusic *play_music();

#endif