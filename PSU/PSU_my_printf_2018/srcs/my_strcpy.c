/*
** EPITECH PROJECT, 2018
** my_strcpy.c
** File description:
** my_strcpy
*/

char *my_strcpy(char *dest, char const *src)
{
    int a;

    for (a = 0; src[a] != '\0'; a = a + 1)
        dest[a] = src[a];
    dest[a] = '\0';
    return (dest);
}
