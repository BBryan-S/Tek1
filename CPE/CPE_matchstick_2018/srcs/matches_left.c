/*
** EPITECH PROJECT, 2018
** CPE_matchstick_2018
** File description:
** matches_left.c
*/

int l_left(char *str)
{
    int nb = 0;

    for (int a = 0; str[a]; a = a + 1) {
        if (str[a] == '|')
            nb = nb + 1;
    }
    return (nb);
}

int matches_left(char **map, int *bigl_left)
{
    int nb = 0;

    for (int a = 0; map[a]; a = a + 1) {
        nb = nb + l_left(map[a]);
        if (l_left(map[*bigl_left]) < l_left(map[a]))
            *bigl_left = a;
    }
    return (nb);
}