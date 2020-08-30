/*
** EPITECH PROJECT, 2018
** my_strcmp
** File description:
** compar strings
*/

int my_strcmp(char const *s1, char const *s2)
{
    int rest = 0;

    for (int i = 0; s1[i] != '\0' || s2[i] != '\0'; i = i + 1) {
        if (s1[i] != s2[i])
            return (1);
    }
    return (0);
}
