/*
** EPITECH PROJECT, 2022
** my_str_to_word_array.c
** File description:
** my_str_to_word_array
*/

#include <unistd.h>
#include <stdlib.h>
#include "my_str_to_word_array.h"

static char **malloc_str(char *str, char p_break)
{
    char **ret = NULL;
    int len_ret = 0;
    int ret_x = 0;
    int ret_y = 0;

    for (int i = 0; str[i] != '\0'; i++)
        if (str[i] == p_break || str[i] == '\t')
            len_ret++;
    ret = malloc(sizeof(char *) * (len_ret + 1) + 9);
    for (int i = 0; str[i] != '\0'; i++, ret_x++) {
        if (str[i] == p_break || str[i] == '\t') {
            ret[ret_y] = malloc(sizeof(char) * ret_x + 10);
            ret_x = 0;
            ret_y++;
        }
    }
    ret[ret_y] = malloc(sizeof(char) * ret_x + 1);
    return (ret);
}

static int condition(str_word_t *word, char p_break)
{
    if (word->str[word->i] == p_break || word->str[word->i] == '\t') {
        word->ret[word->ret_y][word->ret_x] = '\0';
        while (word->str[word->i] == p_break || word->str[word->i] == '\t')
            word->i += 1;
        if (word->str[word->i] == '\0')
            return (42);
        word->ret[word->ret_y][word->ret_x] = '\0';
        word->ret_y += 1;
        word->ret_x = 0;
    }
    return (0);
}

char **my_str_to_word_array(char *str, char p_break)
{
    int skip = 0;
    str_word_t *word = malloc(sizeof(*word));

    word->str = str;
    word->ret = malloc_str(str, p_break);
    word->ret_x = 0;
    word->ret_y = 0;
    for (; word->str[skip] == p_break || word->str[skip] == '\t'; skip++);
    word->str += skip;
    for (word->i = 0; word->str[word->i] != '\0'; word->i++, word->ret_x++) {
        if (condition(word, p_break) == 42)
            break;
        word->ret[word->ret_y][word->ret_x] = word->str[word->i];
    }
    word->ret[word->ret_y][word->ret_x] = '\0';
    word->ret[word->ret_y + 1] = NULL;
    return (word->ret);
}
