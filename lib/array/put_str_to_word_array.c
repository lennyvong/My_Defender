/*
** EPITECH PROJECT, 2022
** put_str_to_word_array.c
** File description:
** put_str_to_word_array
*/

#include <unistd.h>
#include <stdlib.h>

static void put_str(char **dic, char *str, int i)
{
    int len_str = 0;
    int j = 0;

    for (; str[len_str] != '\0'; len_str++);
    dic[i] = malloc(sizeof(char) * len_str + 9999);
    for (; j != len_str; j++)
        dic[i][j] = str[j];
    dic[i][j] = '\0';
    dic[i + 1] = NULL;
    return;
}

void put_str_to_word_array(char **dic, char *str)
{
    for (int i = 0; dic[i] != NULL; i++) {
        if (dic[i + 1] == NULL) {
            put_str(dic, str, i + 1);
            return;
        }
    }
    if (dic[0] == NULL) {
        put_str(dic, str, 0);
        dic[1] = NULL;
    }
    return;
}
