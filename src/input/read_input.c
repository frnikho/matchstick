/*
** EPITECH PROJECT, 2019
** read_input.c
** File description:
** read_input function
*/

#include <stdio.h>
#include "matchstick.h"
#include "myprintf.h"

char *read_input(void)
{
    char *buffer = malloc(READ_SIZE);
    int rd = 0;
    while (rd = read(0, buffer, READ_SIZE) < 0) {

    }
    if (buffer == 0) {
        return (0);
    }
    return (buffer);
}