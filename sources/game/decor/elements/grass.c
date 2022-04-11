/*
** EPITECH PROJECT, 2022
** grass.c
** File description:
** grass
*/

#include "my_structures.h"
#include "my_lib.h"

void preset_grass(game_elements_t *decor, game_textures_t *textures)
{
    set_texture(&(decor->element), textures->grass);
    return;
}
