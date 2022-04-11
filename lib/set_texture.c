/*
** EPITECH PROJECT, 2022
** set_texture.c
** File description:
** set_texture
*/

#include <SFML/Graphics.h>

void set_texture(sfSprite **sprite, sfTexture *texture)
{
    *sprite = sfSprite_create();
    sfSprite_setTexture(*sprite, texture, sfTrue);
    return;
}