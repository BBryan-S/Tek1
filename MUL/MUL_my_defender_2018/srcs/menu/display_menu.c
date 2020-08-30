/*
** EPITECH PROJECT, 2019
** menu
** File description:
** menu
*/

#include <stdlib.h>
#include "../include/my.h"
#include "../include/defender.h"

int compare_text(char *str)
{
    if (my_strcmp(str, "Jouer") == 0)
        return (0);
    if (my_strcmp(str, "Option") == 0)
        return (1);
    if (my_strcmp(str, "Aide") == 0)
        return (2);
    if (my_strcmp(str, "Score") == 0)
        return (3);
    if (my_strcmp(str, "Quitter") == 0)
        return (4);
}

void prepare_text(window_t *win, char *str, sfVector2f pos, int col)
{
    sfColor color = sfYellow;

    if (col == 0)
        color = sfBlue;
    else if (col == 1)
        color = sfRed;
    sfText_setString(win->text_menu, str);
    sfText_setColor(win->text_menu, color);
    sfText_setPosition(win->text_menu, pos);
    sfText_setCharacterSize(win->text_menu, 40);
    if (col == 0 && win->menu_degrees == 0) {
        win->select_menu = compare_text(str);
    }
}

int display_menu_start(game_t *game)
{
    sfVector2f pos;

    pos.x = game->win.width / 2 - 100;
    pos.y = game->win.height / 2 - 100;
    prepare_text(&game->win, "Jouer", pos, get_color(game, pos));
    sfRenderWindow_drawText(game->win.window, game->win.text_menu, NULL);
    pos.y += 100;
    prepare_text(&game->win, "Option", pos, get_color(game, pos));
    sfRenderWindow_drawText(game->win.window, game->win.text_menu, NULL);
    pos.y += 100;
    prepare_text(&game->win, "Aide", pos, get_color(game, pos));
    sfRenderWindow_drawText(game->win.window, game->win.text_menu, NULL);
    pos.y += 100;
    prepare_text(&game->win, "Score", pos, get_color(game, pos));
    sfRenderWindow_drawText(game->win.window, game->win.text_menu, NULL);
    pos.y += 100;
    prepare_text(&game->win, "Quitter", pos, get_color(game, pos));
    sfRenderWindow_drawText(game->win.window, game->win.text_menu, NULL);
    return (game->win.select_menu);
}
