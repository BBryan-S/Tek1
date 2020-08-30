/*
** EPITECH PROJECT, 2018
** PSU_tetris_2018
** File description:
** set_struct.c
*/

#include <ncurses.h>
#include "tetris.h"

void add_list(tetris_t *tet, char *str1, char *str2, int pos)
{
    short a = 0;

    for (; str1 && str1[a]; a++)
        tet->small_command[pos][a] = str1[a];
    tet->small_command[pos][a] = '\0';
    for (a = 0; str2 && str2[a]; a++)
        tet->large_command[pos][a] = str2[a];
    tet->large_command[pos][a] = '\0';
}

setting_t set_setting(void)
{
    setting_t set;

    set.height = 20;
    set.width = 10;
    set.level = 1;
    set.left = KEY_LEFT;
    set.right = KEY_RIGHT;
    set.turn = KEY_UP;
    set.drop = KEY_DOWN;
    set.quit = 'q';
    set.pause = ' ';
    set.next = 1;
    set.debug = 0;
    set.help = 0;
    return (set);
}

void set_list(tetris_t *tet)
{
    add_list(tet, "--help", NULL, 0);
    add_list(tet, "-L", "--level=", 1);
    add_list(tet, "-l", "--key-left=", 2);
    add_list(tet, "-r", "--key-right=", 3);
    add_list(tet, "-t", "--key-turn=", 4);
    add_list(tet, "-d", "--key-drop=", 5);
    add_list(tet, "-q", "--key-quit=", 6);
    add_list(tet, "-p", "--key-pause=", 7);
    add_list(tet, NULL, "--map-size=", 8);
    add_list(tet, "-w", "--without-next", 9);
    add_list(tet, "-D", "--debug", 10);
}

void set_list_command(tetris_t *tet)
{
    tet->com_list[0] = display_help;
    tet->com_list[1] = change_level;
    tet->com_list[2] = change_left;
    tet->com_list[3] = change_right;
    tet->com_list[4] = change_turn;
    tet->com_list[5] = change_drop;
    tet->com_list[6] = change_quit;
    tet->com_list[7] = change_pause;
    tet->com_list[8] = change_size;
    tet->com_list[9] = change_next;
    tet->com_list[10] = change_debug;
}

tetris_t set_struct(void)
{
    tetris_t tet;

    tet.setting = set_setting();
    set_list(&tet);
    set_list_command(&tet);
    return (tet);
}