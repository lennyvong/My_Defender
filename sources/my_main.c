/*
** EPITECH PROJECT, 2022
** main.c
** File description:
** my_main
*/

#include "my_macro.h"

void my_defender(void);

int main(int ac, char **av) {
    if (ac > 2)
        return (ERROR);
    my_defender();
    return (SUCCESS);
}
