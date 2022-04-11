/*
** EPITECH PROJECT, 2021
** my_getnbr.c
** File description:
** get nbr
*/

#include <stdlib.h>

int my_getnbr(char const *str)
{
    int a = 0;
    int b = 1;
    int i = 0;

    if (str == NULL)
        return (-1);
    while ((*str < '0' || *str > '9') && *str != 0) {
        str = str + 1;
        i = i + 1;
    }
    if (i > 0 && *(str - 1) == '-')
        b = -1;
    while (*str != 0 && *str >= '0' && *str <= '9') {
        a = a * 10;
        a = a + *str - 48;
        str = str + 1;
    }
    a = a * b;
    return (a);
}
