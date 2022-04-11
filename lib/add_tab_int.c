/*
** EPITECH PROJECT, 2022
** add_tab_int.c
** File description:
** add_tab_int
*/

void add_tab_int(int *tab, int value)
{
    int i = 0;

    for (; tab[i] != -1; i++);
    tab[i] = value;
    tab[i + 1] = -1;
    return;
}