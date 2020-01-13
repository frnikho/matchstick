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
    int nbr;
    while (1) {
        nbr = random() % (max_line + 1) + 1;
        if (get_matches_line(board, max_line) > 0)
            break;
    }
    return (nbr);
}

int get_random_matches(char **board, int line, int max_matches)
{
    int current_line_matches = get_matches_line(board, line);
    if (current_line_matches > max_matches) {
        int nbr = random() % (max_matches + 1) + 1;
        return (nbr);
    } else {
        return (max_matches);
    }
}

void handle_ia_input(char **board, int max_matches)
{
    my_putchar('\n');
    int line = get_random_line(board, max_matches);
    int removed_matches = get_random_matches(board, line, max_matches);
    remove_match(board, line, removed_matches);
    my_printf("IA removed %d into line %d\n", removed_matches, line);
}
