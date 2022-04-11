/*
** EPITECH PROJECT, 2022
** my_runner
** File description:
** my_itoa
*/

#include <stdlib.h>

char *my_itoa(int nb)
{
    int	len = 0;
    int	tmp = 0;
    char *str = NULL;

    tmp = nb;
    len = 0;
    while (tmp > 0) {
        tmp /= 10;
        len++;
    }
    str = malloc(sizeof(*str) * (len + 1));
    str[len] = '\0';
    while (len--) {
        str[len] = nb % 10  + '0';
        nb /= 10;
    }
    return (str);
}
