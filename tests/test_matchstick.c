/*
** EPITECH PROJECT, 2019
** test_matchstick.c
** File description:
** unit test
*/

#include "matchstick.h"
#include "my.h"

#include <criterion/criterion.h>

Test(get_last_line_matches, normal_4)
{
    int max_matches = get_last_line_matches(4);
    cr_expect_eq(max_matches, 7);
}

Test(get_last_line_matches, normal_2)
{
    int max_matches = get_last_line_matches(2);
    cr_expect_eq(max_matches, 3);
}

Test(get_first_and_last_line, normal_4)
{
    int max_matches = get_last_line_matches(4);
    char *test = get_first_and_last_line(max_matches);
    cr_expect_eq(my_strlen(test) - 1, 9);
}

Test(get_first_and_last_line, normal_2)
{
    int max_matches = get_last_line_matches(2);
    char *test = get_first_and_last_line(max_matches);
    cr_expect_eq(my_strlen(test) - 1, 5);
}

Test(get_line_matches, normal)
{
    int matches = 5;
    int space = 1;
    char *line = get_line_matches(matches, space);
}

Test(create_board, size_1)
{
    char **board = create_board(1);
    cr_expect_null(board);
}

Test(create_board, size_2)
{
    char **board = create_board(2);
    cr_expect_str_eq(board[0], "*****\n");
    cr_expect_str_eq(board[1], "* | *\n");
    cr_expect_str_eq(board[2], "*|||*\n");
    cr_expect_str_eq(board[3], "*****\n");
}

Test(create_board, size_4)
{
    char **board = create_board(4);
    cr_expect_str_eq(board[0], "*********\n");
    cr_expect_str_eq(board[1], "*   |   *\n");
    cr_expect_str_eq(board[2], "*  |||  *\n");
    cr_expect_str_eq(board[3], "* ||||| *\n");
    cr_expect_str_eq(board[4], "*|||||||*\n");
    cr_expect_str_eq(board[5], "*********\n");
}

Test(create_board, size_9)
{
    char **board = create_board(9);
    cr_expect_str_eq(board[0], "*******************\n");
    cr_expect_str_eq(board[1], "*        |        *\n");
    cr_expect_str_eq(board[2], "*       |||       *\n");
    cr_expect_str_eq(board[3], "*      |||||      *\n");
    cr_expect_str_eq(board[4], "*     |||||||     *\n");
    cr_expect_str_eq(board[5], "*    |||||||||    *\n");
    cr_expect_str_eq(board[6], "*   |||||||||||   *\n");
    cr_expect_str_eq(board[7], "*  |||||||||||||  *\n");
    cr_expect_str_eq(board[8], "* ||||||||||||||| *\n");
    cr_expect_str_eq(board[9], "*|||||||||||||||||*\n");
    cr_expect_str_eq(board[10], "*******************\n");
}

Test(create_board, negative_size_line)
{
    char **board = create_board(-4);
    cr_expect_null(board);
}

Test(create_board, zero_size_line)
{
    char **board = create_board(0);
    cr_expect_null(board);
}

Test(create_board, wrong_size_line)
{
    char **board = create_board(1);
    cr_expect_null(board);
}
