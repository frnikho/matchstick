/*
** EPITECH PROJECT, 2019
** ia.c
** File description:
** ia function
*/

#include "myprintf.h"
#include "matchstick.h"

int get_random_line(char **board, int max_line)
{
    while (1) {
        int nbr = random() % (max_line + 1) + 1;
        if (get_matches_line(board, nbr) >= 1)
            return (nbr);
    }
}

int get_random_matches(char **board, int line, int max_matches)
{
    while (1) {
        int nbr = random() % (max_matches + 1) + 1;
        if (get_matches_line(board, line) >= nbr)
            return (nbr);
    }
}

void handle_ia_input(char **board, int max_lines, int max_matches)
{
    int line = get_random_line(board, max_lines);
    int matches = get_random_matches(board, line, max_matches);
    my_putchar('\n');
    my_putstr("AI's turn...\n");
    remove_match(board, line, matches);
    my_printf("AI removed %d match(es) from line %d\n", matches, line);
}