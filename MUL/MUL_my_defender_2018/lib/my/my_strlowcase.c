/*
** EPITECH PROJECT, 2018
** my_strlowcase
** File description:
** lowcase string
*/

char *my_strlowcase(char *str)
{
    for (int i = 0; str[i] != '\0'; i = i + 1) {
        if ('A' <= str[i] && str[i] <= 'Z')
            str[i] = str[i] + 32;
    }
    return (str);
}
