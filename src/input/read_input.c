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
    char *buffer = malloc(1024);
    size_t size = 0;

    getline(&buffer, &size, stdin);
    if (buffer == 0) {
        return (0);
    }
    return (buffer);
}