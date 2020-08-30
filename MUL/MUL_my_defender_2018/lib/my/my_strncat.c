/*
** EPITECH PROJECT, 2018
** my_strncat
** File description:
** concatenates n carac
*/

char *my_strncat(char *dest, char const *src, int nb)
{
    int i = 0;
    int j = 0;

    while (dest[i] != '\0')
        i = i + 1;
    while (src[j] != '\0')
        j = j + 1;
    if (nb > j)
        nb = j;
    for (j = 0; j < nb; j = j + 1) {
        dest[i] = src[j];
        i = i + 1;
    }
    dest[i] = '\0';
    return (dest);
}
