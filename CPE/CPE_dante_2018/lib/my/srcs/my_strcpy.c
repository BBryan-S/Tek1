/*
** EPITECH PROJECT, 2019
** lib
** File description:
** my_strcpy
*/

void my_strcpy(char *dest, char *src)
{
    int i;

    for (i = 0; src[i] != '\0' && src[i] != '\n'; i++)
        dest[i] = src[i];
    dest[i] = '\0';
}