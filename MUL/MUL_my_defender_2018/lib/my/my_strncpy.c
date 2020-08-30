/*
** EPITECH PROJECT, 2018
** my_strncpy
** File description:
** copy n string
*/

char *my_strncpy(char *dest, char const *src, int n_a, int n_b)
{
    int i = 0;
    int j = 0;

    for (i = n_a; i < n_b && src[i] != '\0'; i++, j++)
        dest[j] = src[i];
    if (n_b > i)
        dest[j] = '\0';
    return (dest);
}
