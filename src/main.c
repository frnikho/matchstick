/*
** EPITECH PROJECT, 2019
** main.c
** File description:
** main function
*/

#include "matchstick.h"

int main(int argc, char **argv)
{
    if (argc != 3) {
        my_strerr("Invalid arguments !\nUSAGE:\n");
        my_strerr("./matchstick line maxmatches\n");
        return (84);
    }
    int line = my_getnbr(argv[1]);
    int max_matches = my_getnbr(argv[2]);
    if (line < 2 || line > 99 || max_matches <= 0) {
        my_strerr("Invalid line size or matches (1 < line < 100)\n");
        my_strerr("USAGE:\n./matchstick line maxmatches\n");
        return (84);
    }
    int result = matchstick(line, max_matches);
    if (result == 2) {
        my_putstr("You lost, too bad...\n");
        return (2);
    } else if (result == 1) {
        my_putstr("I lost... snif... but I'll get you next time!!\n");
        return (1);
    }
}