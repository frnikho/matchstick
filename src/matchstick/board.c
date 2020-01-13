/*
** EPITECH PROJECT, 2019
** board.c
** File description:
** board function
*/

#include "matchstick.h"

char *get_first_and_last_line(int max_matches)
{
    char *c = malloc(sizeof(char) * (max_matches + 2) + 1024);
    int index = 0;
    for (; index < max_matches+2; index++) {
        c[index] = '*';
    }
    c[index] = '\n';
    return (c);
}

char *get_line_matches(int matches, int space)
{
    char *c = malloc(sizeof(char) * (matches + space + 3) + 1024);
    int index = space;
    c[0] = '*';
    for (int i = 1; i < index; i++) {
        c[i] = ' ';
    }
    for (; index < matches+2 + space; index++) {
        c[index] = '|';
    }
    for (int i = index + 1; i < (index + space); i++) {
        c[i-1] = ' ';
    }
    c[index+space-1] = '*';
    c[index+space] = '\n';
    c[index+space+1] = '\0';
    return (c);
}

int get_last_line_matches(int line)
{
    int matches = 3;
    for (int i = 1; i < line - 1; i++) {
        matches+=2;
    }
    return (matches);
}

char **create_board(int line)
{
    if (line < 2)
        return (0);
    char **board = malloc(sizeof(char) * ((line) + 2) + 1024);
    int max_matches = get_last_line_matches(line);

    int space = 0;
    int match = max_matches;

    for (int i = line + 1; i >= 1; i--) {
        board[i] = get_line_matches(match, space);
        match -= 2;
        space++;
    }
    board[0] = get_first_and_last_line(max_matches);
    board[line+1] = get_first_and_last_line(max_matches);
    board[line+2] = NULL;
    return (board);
}

void display_board(char **board)
{
    for (int i = 0; board[i] != 0; i++) {
        my_putstr(board[i]);
    }
}