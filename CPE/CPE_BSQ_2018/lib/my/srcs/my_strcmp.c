/*
** EPITECH PROJECT, 2018
** my_strcmp.c
** File description:
** my_strcmp
*/

int my_strcmp(char const *s1, char const *s2)
{
    int cmp = 0;

    for (int a = 0; s1[a] != '\0' || s2[a] != '\0'; a = a + 1) {
        cmp = s1[a] - s2[a];
        if (cmp != 0)
            return (cmp);
    }
    return (cmp);
}
