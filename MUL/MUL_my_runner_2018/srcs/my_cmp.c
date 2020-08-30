/*
** EPITECH PROJECT, 2018
** MUL_my_runner_2018
** File description:
** my_cmp.c
*/

int my_cmp(char *str1, char *str2)
{
    int a = 0;
    int b = 0;

    for (; str1[a]; a = a + 1);
    for (; str2[b]; b = b + 1);
    if (a != b)
        return (0);
    for (int c = 0; str1[c]; c = c + 1) {
        if (str1[c] != str2[c])
            return (0);
    }
    return (1);
}