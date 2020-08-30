/*
** EPITECH PROJECT, 2018
** main.c
** File description:
** mainc
*/

#include <stdlib.h>
#include "../include/my.h"
#include "../include/defender.h"
#include <unistd.h>
#include <sys/types.h>
#include <stdio.h>
#include <fcntl.h>
#include <string.h>

void destroy_sprite(image_t *im)
{
    sfSprite_destroy(im->bg_sprite);
    sfSprite_destroy(im->entity_sprite);
    sfSprite_destroy(im->help_sprite);
    sfSprite_destroy(im->menu_sprite);
}

void clear_entity(game_t *gt)
{
    if (gt->audio.effet_enable == 1) {
        sfMusic_stop(gt->audio.effect);
        sfMusic_destroy(gt->audio.effect);
    }
    if (gt->audio.music_enable == 1) {
        sfMusic_stop(gt->audio.music);
        sfMusic_destroy(gt->audio.music);
    }
    destroy_sprite(&gt->image);
}

int register_score(int score)
{
    int fd;
    char *buffer = my_itoa(score);
    char *res = my_alloc(13);
    char *stock = my_alloc(13);
    int i = 0;

    fd = open(".score.txt", O_RDWR);
    while (read(fd, res, 1) != 0) {
        stock[i] = res[0];
        i++;
    }
    if (score > my_getnbr(stock))
        write(fd, buffer, my_strlen(buffer));
    close(fd);
    return (0);
}

int main(int ac, char **av)
{
    game_t game;
    int end = 0;

    configure_window(&game.win);
    while (end >= 0) {
        configure_game(&game, &game.timer);
        play_music(&game, M_MUSIC);
        if (launch_menu(&game) == - 1)
            return (0);
        prepare_entity(&game);
        sfMusic_destroy(game.audio.music);
        play_music(&game, G_MUSIC);
        end = launch_game(&game);
    }
    clear_entity(&game);
    if (end == -42)
        my_putstr("game over :'(\n");
    else if (end == -1)
        sfRenderWindow_close(game.win.window);
    return (register_score(game.info.score));
}
