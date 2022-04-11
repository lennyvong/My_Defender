/*
** EPITECH PROJECT, 2022
** my_strcat
** File description:
** my_strcat
*/

#include <stdlib.h>

int my_strlen(char const *len);

char *my_strcat(char *str1, char *str2)
{
    int nb_char = my_strlen(str1) + my_strlen(str2);
    char *ret = malloc(sizeof(char) * nb_char + 1);
    int i_ret = 0;

    for (int i = 0; str1[i] != '\0'; i++, i_ret++)
        ret[i_ret] = str1[i];
    for (int i = 0; str2[i] != '\0'; i++, i_ret++)
        ret[i_ret] = str2[i];
    ret[i_ret] = '\0';
    return ret;
}
