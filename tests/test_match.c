/*
** EPITECH PROJECT, 2019
** test_match.c
** File description:
** unit test
*/

#include <criterion/criterion.h>
#include "matchstick.h"

Test(get_matches_line, line_1)
{
    char **board = create_board(9);
    int result = get_matches_line(board, 1);
    cr_expect_eq(result, 1);
}

Test(get_matches_line, line_3)
{
    char **board = create_board(9);
    int result = get_matches_line(board, 3);
    cr_expect_eq(result, 5);
}

Test(get_matches_line, zero_line)
{
    char **board = create_board(7);
    int result = get_matches_line(board, 0);
    cr_expect_eq(result, -1);
}

Test(get_matches_line, wrong_line_8)
{
    char **board = create_board(7);
    int result = get_matches_line(board, 8);
    cr_expect_eq(result, -1);
}

Test(get_matches_line, line_minus_2)
{
    char **board = create_board(7);
    int result = get_matches_line(board, -2);
    cr_expect_eq(result, -1);
}

Test(remove_match, remove_1_match)
{
    char **board = create_board(8);
    remove_match(board, 3, 3);
    int result = get_matches_line(board, 3);
    cr_expect_eq(result, 2);
}

Test(remove_match, remove_3_match)
{
    char **board = create_board(9);
    remove_match(board, 2, 1);
    int result = get_matches_line(board, 2);
    cr_expect_eq(result, 2);
}

Test(remove_match, remove_to_much_match)
{
    char **board = create_board(9);
    remove_match(board, 2, 4);
    int result = get_matches_line(board, 2);
    cr_expect_eq(result, 3);
}

Test(remove_match, remove_to_no_enough)
{
    char **board = create_board(9);
    remove_match(board, 3, 0);
    int result = get_matches_line(board, 3);
    cr_expect_eq(result, 5);
}