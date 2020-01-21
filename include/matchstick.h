/*
** EPITECH PROJECT, 2019
** matchstick
** File description:
** header file
*/

#ifndef CPE_MATCHSTICK_2019_MATCHSTICK_H
#define CPE_MATCHSTICK_2019_MATCHSTICK_H

#include "my.h"
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

#define READ_SIZE 1024

char *get_first_and_last_line(int line);
char *get_line_matches(int matches, int space);
int get_last_line_matches(int line);
char **create_board(int line);
void display_board(char **board);

char *read_input(void);
int handle_user_input(char **board, int line);
void handle_ia_input(char **board, int max_matches);

int get_matches_line(char **board, int line);
int get_all_matches(char **board);
int remove_match(char **board, int line, int matches);

int matchstick(int line, int max_matches);

int game_input(char **board, int lines, int max_lines);

#endif
