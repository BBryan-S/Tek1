/*
** EPITECH PROJECT, 2018
** test.c
** File description:
** test
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "../include/my.h"

void redirect_all_std ( void )
{
    cr_redirect_stdout () ;
    cr_redirect_stderr () ;
}

Test (my_printf, simple_string, . init = redirect_all_std )
{
    my_printf("hello world");
    cr_assert_stdout_eq_str("hello world");
}

Test (my_printf, one_arg_flags_s, . init = redirect_all_std )
{
    my_printf("%s", "Hello World\n");
    cr_assert_stdout_eq_str("Hello World\n");
}

Test (my_printf, one_arg_flags_c, . init = redirect_all_std )
{
    my_printf("%c", 'A');
    cr_assert_stdout_eq_str("A");
}

Test (my_printf, one_arg_flags_i, . init = redirect_all_std )
{
    my_printf("%i", 36457);
    cr_assert_stdout_eq_str("36457");
}

Test (my_printf, one_arg_flags_d, . init = redirect_all_std )
{
    my_printf("%d", 36457);
    cr_assert_stdout_eq_str("36457");
}

Test (my_printf, one_arg_flags_o, . init = redirect_all_std )
{
    my_printf("%o", 8);
    cr_assert_stdout_eq_str("10");
}

Test (my_printf, one_arg_flags_b, . init = redirect_all_std )
{
    my_printf("%b", 8);
    cr_assert_stdout_eq_str("1000");
}

Test (my_printf, one_arg_flags_x, . init = redirect_all_std )
{
    my_printf("%x", 15);
    cr_assert_stdout_eq_str("f");
}

Test (my_printf, one_arg_flags_xx, . init = redirect_all_std )
{
    my_printf("%X", 15);
    cr_assert_stdout_eq_str("F");
}

Test (my_printf, one_arg_flags_u, . init = redirect_all_std )
{
    my_printf("%u", 15);
    cr_assert_stdout_eq_str("15");
}

Test (my_printf, one_arg_flags_h, . init = redirect_all_std )
{
    my_printf("%h", 15);
    cr_assert_stdout_eq_str("15");
}

Test (my_printf, one_arg_flags_l, . init = redirect_all_std )
{
    my_printf("%l", 1502947432832);
    cr_assert_stdout_eq_str("1502947432832");
}

Test (my_printf, one_arg_flags_percent, . init = redirect_all_std )
{
    my_printf("%%");
    cr_assert_stdout_eq_str("%");
}

Test (my_printf, multi_arg, . init = redirect_all_std )
{
    my_printf("Hello World\n%c\n%s\n%i", 'A', "ABC", 453);
    cr_assert_stdout_eq_str("Hello World\nA\nABC\n453");
}
