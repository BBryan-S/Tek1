/*
** EPITECH PROJECT, 2018
** set_map.c
** File description:
** set_map
*/

int check_move_box(char c)
{
    if (c == ' ' || c == 'O')
        return (0);
    return (-1);
}

void move_left(char **map, char **stock, int y, int x)
{
    if (map[y][x - 1] != '#') {
        if (map[y][x - 1] == 'X' && check_move_box(map[y][x - 2]) == -1)
            return;
        else if (map[y][x - 1] == 'X')
            map[y][x - 2] = 'X';
        map[y][x] = ' ';
        map[y][x - 1] = 'P';
        if (stock[y][x] == 'O')
            map[y][x] = 'O';
    }
}

void move_right(char **map, char **stock, int y, int x)
{
    if (map[y][x + 1] != '#') {
        if (map[y][x + 1] == 'X' && check_move_box(map[y][x + 2]) == -1)
            return;
        else if (map[y][x + 1] == 'X')
            map[y][x + 2] = 'X';
        map[y][x] = ' ';
        map[y][x + 1] = 'P';
        if (stock[y][x] == 'O')
            map[y][x] = 'O';
    }
}

void move_up(char **map, char **stock, int y, int x)
{
    if (map[y - 1][x] != '#') {
        if (map[y - 1][x] == 'X' && check_move_box(map[y - 2][x]) == -1)
            return;
        else if (map[y - 1][x] == 'X')
            map[y - 2][x] = 'X';
        map[y][x] = ' ';
        map[y - 1][x] = 'P';
        if (stock[y][x] == 'O')
            map[y][x] = 'O';
    }
}

void move_down(char **map, char **stock, int y, int x)
{
    if (map[y + 1][x] != '#') {
        if (map[y + 1][x] == 'X' && check_move_box(map[y + 2][x]) == -1)
            return;
        else if (map[y + 1][x] == 'X')
            map[y + 2][x] = 'X';
        map[y][x] = ' ';
        map[y + 1][x] = 'P';
        if (stock[y][x] == 'O')
            map[y][x] = 'O';
    }
}