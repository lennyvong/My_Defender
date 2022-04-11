/*
** EPITECH PROJECT, 2022
** my_array_len.c
** File description:
** my_array_len
*/

#include <unistd.h>

int my_array_len(char **array)
{
    int ret = 0;

    for (; array[ret] != NULL; ret += 1);
    return (ret);
}
