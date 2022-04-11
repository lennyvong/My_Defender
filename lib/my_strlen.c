/*
** EPITECH PROJECT, 2021
** my_strlen
** File description:
** function that count the number of characters
*/

int my_strlen(char const *len)
{
    int i = 0;

    while (len[i] != '\0')
        i = i + 1;
    return (i);
}
