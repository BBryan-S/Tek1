/*
** EPITECH PROJECT, 2019
** configure
** File description:
** configure
*/

#include <stdlib.h>
#include "../include/my.h"
#include "../include/defender.h"

void configure_window(window_t *win)
{
    sfVideoMode mode = {1920, 1080, 32};

    win->freq = 60;
    win->width = 1920;
    win->height = 1080;
    win->window = sfRenderWindow_create(mode, "Defender",
    sfResize | sfClose, NULL);
    sfRenderWindow_setFramerateLimit(win->window, win->freq);
    win->position_map = prep_mal();
    win->font_menu = sfFont_createFromFile(FONT_MENU_PATH);
    win->font_info = sfFont_createFromFile(FONT_INFO_PATH);
    win->text_menu = sfText_create();
    win->text_info = sfText_create();
    win->mouse_vect.x = -1;
    win->mouse_vect.y = -1;
    win->clic_vect.x = -1;
    win->clic_vect.y = -1;
    win->tower_vect.x = -1;
    win->tower_vect.y = -1;
    win->select_menu = -1;
}

void configure_image(image_t *im)
{
    im->entity_sprite = sfSprite_create();
    im->pause_sprite = sfSprite_create();
    im->bg_sprite = sfSprite_create();
    im->menu_sprite = sfSprite_create();
    im->game_end_sprite = sfSprite_create();
    im->help_sprite = sfSprite_create();
    set_tex_sprite(im->help_tex, im->help_sprite, HELP_PATH);
    set_tex_sprite(im->entity_tex, im->entity_sprite, ENTITY_PATH);
    set_tex_sprite(im->pause_tex, im->pause_sprite, PAUSE_PATH);
    set_tex_sprite(im->bg_tex, im->bg_sprite, BG_PATH);
    set_tex_sprite(im->menu_tex, im->menu_sprite, MENU_PATH);
    set_tex_sprite(im->game_end_tex, im->game_end_sprite, END_PATH);
    im->enemi_rect = malloc(sizeof(sfIntRect) * 6);
    im->tower_rect = malloc(sizeof(sfIntRect) * 3);
    prepare_rect(im);
}

void configure_stuff(audio_t *audio, window_t *win)
{
    audio->music_enable = 1;
    audio->effet_enable = 1;
    sfText_setFont(win->text_menu, win->font_menu);
    sfText_setFont(win->text_info, win->font_info);
}

void configure_info(info_t *game)
{
    game->score = 0;
    game->money = 300;
    game->difficulty = 1;
    game->is_pause = 0;
    game->panel_pos.x = -1;
    game->panel_pos.y = -1;
    game->is_panel = 0;
    game->panel_display = 0;
    game->max_tour = 1;
    game->actual_tour = 0;
    game->actual_monster = 0;
}

int configure_game(game_t *game, timergame_t *timer)
{
    configure_image(&game->image);
    configure_stuff(&game->audio, &game->win);
    configure_info(&game->info);
    configure_timer(timer);
    prepare_map(game);
    return (0);
}
