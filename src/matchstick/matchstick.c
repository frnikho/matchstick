/*
** EPITECH PROJECT, 2019
** matchstick
** File description:
** matchstick function
*/

#include "matchstick.h"

int matchstick(int line, int max_matches)
{
    int game = 1;
    char **board = create_board(line);
    while (game) {
        display_board(board);
        handle_user_input(board, line);
        display_board(board);
        handle_ia_input(board, max_matches);
        if (get_all_matches(board) < 1) {
            my_putstr("GAME END ! IA IN PROGRESS :)\n");
            return (0);
        }
    }
}