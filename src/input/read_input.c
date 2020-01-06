/*
** EPITECH PROJECT, 2019
** read_input.c
** File description:
** read_input function
*/

#include "matchstick.h"
#include "myprintf.h"

char *read_input(void)
{
    char *buffer = malloc(READ_SIZE);
    int rd = 0;
    while (rd = read(0, buffer, READ_SIZE) < 0) {}
    return (buffer);
}

int get_input_line(int line)
{
    int good_line = 0;
    while (!good_line) {
        my_putstr("Line: ");
        int input = my_getnbr(read_input());
        if (input < 0) {
            my_putstr("Error: invalid input (positive number expected)\n");
            continue;
        }
        if (input == 0 || input > line) {
            my_putstr("Error: this line is out of range\n");
            continue;
        }
        good_line = 1;
    }
}

int get_input_matches(int line)
{
    int good_line = 0;
    while (!good_line) {
        my_putstr("Matches: ");
        int input = my_getnbr(read_input());
        if (input == 0) {
            my_putstr("Error: you have to remove at least one match\n");
            continue;
        }
        good_line = 1;
        return (input);
    }
}

int handle_user_input(char **board, int line)
{
    my_putchar('\n');
    my_putstr("Your turn:\n");
    int sl = get_input_line(line);
    int sm = get_input_matches(line);
    while (remove_match(board, sl, sm) == -1) {
        my_putstr("Error: not enough matches on this line\n");
        sm = get_input_matches(line);
    }
    my_printf("Player removed %d match(es) from line %d\n", sm, sl);
}

int handle_ia_input(char **board, int line)
{
    my_putchar('\n');
    my_putstr("AI's turn...\n");
    my_putstr("AI removed 2 match(es) from line 3\n");
}