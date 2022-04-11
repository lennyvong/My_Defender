/*
** EPITECH PROJECT, 2022
** my_arraycpy.c
** File description:
** my_arraycpy
*/

#include <stdlib.h>

void put_str_to_word_array(char **dic, char *str);
int my_array_len(char **array);

char **my_arraycpy(char **array)
{
    char **ret = malloc(sizeof(char *) * my_array_len(array) + 10);

    ret[0] = NULL;
    for (int i = 0; array[i] != NULL; i++) {
        put_str_to_word_array(ret, array[i]);
    }
    return (ret);
}
