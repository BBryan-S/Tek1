/*
** EPITECH PROJECT, 2019
** menu
** File description:
** menu
*/

#include <stdlib.h>
#include "../include/my.h"
#include "../include/defender.h"

char **prepare_option_choice(game_t *game)
{
    char **str = malloc(sizeof(char *) * 6);

    for (int i = 0; i < 6; i++) {
        str[i] = my_alloc(30);
    }
    str[0] = my_strcat("Frequence : ", my_itoa(game->win.freq));
    str[1] = my_strcat("Difficulte : ", my_itoa(game->info.difficulty));
    if (game->audio.music_enable == 0) {
        str[2] = "Musique : Off";
        sfMusic_pause(game->audio.music);
    } else {
        str[2] = "Musique : On";
        sfMusic_play(game->audio.music);
    }
    if (game->audio.effet_enable == 0)
        str[3] = "Bruitage : Off";
    else
        str[3] = "Bruitage : On";
    str[4] = my_strcat("Argent de depart : ", my_itoa(game->info.money));
    str[5] = NULL;
    return (str);

}

int compare_option(char *str)
{
    if (my_strncmp(str, "Frequence", 0, 9) == 0)
        return (5);
    else if (my_strncmp(str, "Difficulte", 0, 10) == 0)
        return (6);
    else if (my_strncmp(str, "Musique", 0, 7) == 0)
        return (7);
    else
        return (next_compare(str));
}

void prepare_op(window_t *win, char *str, sfVector2f pos, int col)
{
    sfColor color = sfYellow;

    if (col == 0)
        color = sfBlue;
    else if (col == 1)
        color = sfRed;
    sfText_setString(win->text_menu, str);
    sfText_setColor(win->text_menu, color);
    sfText_setPosition(win->text_menu, pos);
    sfText_setCharacterSize(win->text_menu, 30);
    if (col == 0)
        win->select_option = compare_option(str);
}

int display_menu_option(game_t *game)
{
    sfVector2f pos;
    int r = 0;
    char **option = prepare_option_choice(game);

    pos.x = game->win.width / 2 - 100;
    pos.y = game->win.height / 2 - 100;
    for (int i = 0; option[i] != NULL; i++) {
        prepare_op(&game->win, option[i], pos, get_color(game, pos));
        sfRenderWindow_drawText(game->win.window, game->win.text_menu, NULL);
        pos.y += 100;
    }
    prepare_op(&game->win, "Retour", pos, get_color(game, pos));
    sfRenderWindow_drawText(game->win.window, game->win.text_menu, NULL);
    return (game->win.select_option);
}

void menu_option(game_t *gt)
{
    gt->win.menu_degrees = 1;
    sfRenderWindow_drawSprite(gt->win.window, gt->image.menu_sprite, NULL);
    change_option(display_menu_option(gt), gt);
}
