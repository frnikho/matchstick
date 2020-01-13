/*
** EPITECH PROJECT, 2019
** match.c
** File description:
** match function
*/

#include "matchstick.h"

int get_all_matches(char **board)
{
    int match = 0;

    for (int i = 0; board[i] != 0; i++) {
        for (int j = 0; board[i][j] != 0; j++) {
            board[i][j] == '|' ? match++ : 0;
        }
    }

    return (match);
}

int get_matches_line(char **board, int line)
{
    if (line <= 0 || board[line+1] == 0)
        return (-1);
    int count = 0;
    for (int i = 0; board[line][i] != 0; i++) {
        if (board[line][i] == '|') {
            count++;
        }
    }

    return (count);
}

int remove_match(char **board, int line, int matches)
{
    int cm = get_matches_line(board, line);
    if (cm < matches)
        return (-1);
    int first = 0;
    for (int i = 0; board[line][i] != 0; i++) {
        if (board[line][i] == '|') {
            first = i;
            break;
        }
    }
    for (int i = (first + cm)-1; i > (cm + first - matches) - 1; i--) {
        board[line][i] = ' ';
    }
    return (0);
}