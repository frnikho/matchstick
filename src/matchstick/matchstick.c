/*
** EPITECH PROJECT, 2019
** matchstick
** File description:
** matchstick function
*/

#include "matchstick.h"

int check_win(char **board, int is_player)
{
    if (get_all_matches(board) < 1) {
        if (is_player)
            return (1);
        else
            return (2);
    }
}

int matchstick(int line, int max_matches)
{
    int game = 1;
    char **board = create_board(line);
    while (game) {
        srandom(time(NULL));
        display_board(board);
        if (game_input(board, line, max_matches) == -1)
            return (0);
        if (check_win(board, 1) == 1) {
            display_board(board);
            return (2);
        }
        display_board(board);
        handle_ia_input(board, line, max_matches);
        if (check_win(board, 0) == 2) {
            display_board(board);
            return (1);
        }
    }
}