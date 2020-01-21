/*
** EPITECH PROJECT, 2019
** game_input.c
** File description:
** game_input function
*/

#include "myprintf.h"
#include "my.h"
#include "matchstick.h"

int check_input(char **board, char *read, int current_line)
{
    int matches_line = get_matches_line(board, current_line);
    for (int i = 0; read[i] != 0; i++) {
        if (read[i] >= '0' && read[i] <= '9' || read[i] == '\n')
            continue;
        else {
            my_putstr("Error: invalid input (positive number expected)\n");
            return (-1);
        }
    }
    int current_matches = my_getnbr(read);
    if (current_matches == 0) {
        my_putstr("Error: you have to remove at least one match\n");
        return (-1);
    }
    if (current_matches > matches_line) {
        my_putstr("Error: not enough matches on this line\n");
        return (-1);
    }
    return (1);
}

int get_line_input(char **board, int lines, int max_matches)
{
    int current_line = 0;
    while (1) {
        my_putstr("Line: ");
        char *read = read_input();
        if (read && read[0] == 0)
            return (-1);
        current_line = my_getnbr(read);
        if (current_line == 0 || current_line > lines) {
            my_putstr("Error: this line is out of range\n");
            continue;
        }
        break;
    }
    return (current_line);
}

int get_match_input(char **board, int current_line, int max_matches)
{
    int is_correct = 0;
    int current_matches = 0;

    while (1) {
        my_putstr("Matches: ");
        char *read = read_input();
        if (read && read[0] == 0)
            return (-1);
        if (check_input(board, read, current_line) == -1)
            return (0);
        current_matches = my_getnbr(read);
        break;
    }

    return (current_matches);
}

int game_input(char **board, int lines, int max_lines)
{
    my_putchar('\n');
    int cl = 0;
    int cm = 0;
    while (1) {
        cl = get_line_input(board, lines, max_lines);
        if (cl == -1)
            return (-1);
        cm = get_match_input(board, cl, max_lines);
        if (cm == 0)
            continue;
        if (cm == -1)
            return (-1);
        break;
    }
    remove_match(board, cl, cm);
    my_printf("Player removed %d match(es) from line %d\n", cl, cm);
}