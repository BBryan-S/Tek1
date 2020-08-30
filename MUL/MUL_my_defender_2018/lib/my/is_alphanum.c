/*
** EPITECH PROJECT, 2018
** is_alpha_num
** File description:
** return 1 if alphanum
*/

int is_alpha(char c)
{
    if (('A' <= c && c <= 'Z') || ('a' <= c && c <= 'z'))
        return (1);
    return (0);
}

int is_num(char c)
{
    if ('0' <= c && c <= '9')
        return (1);
    return (0);
}
