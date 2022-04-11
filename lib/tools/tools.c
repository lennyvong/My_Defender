/*
** EPITECH PROJECT, 2022
** tools.c
** File description:
** tools.c
*/

#include <SFML/Graphics.h>

sfIntRect get_rect(int top, int left, int width, int height)
{
    sfIntRect rect;

    rect.top = top;
    rect.left = left;
    rect.width = width;
    rect.height = height;
    return rect;
}
