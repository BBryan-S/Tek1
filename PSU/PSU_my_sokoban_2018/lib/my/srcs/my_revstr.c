/*
** EPITECH PROJECT, 2018
** my_revstr.c
** File description:
** my_revstr
*/

char *my_revstr(char *str)
{
    char c;
    int a = 0;
    int b = 0;

    for (b = 0; str[b] != '\0'; b = b + 1);
    b = b - 1;
    while (a <= b) {
        c = str[a];
        str[a] = str[b];
        str[b] = c;
        a = a + 1;
        b = b - 1;
    }
    while (str[a] != '\0')
        a = a + 1;
    str[a] = '\0';
    return (str);
}
