/*
** EPITECH PROJECT, 2022
** road.c
** File description:
** road
*/

#include "my_structures.h"
#include "my_lib.h"

void preset_road(game_elements_t *decor, game_textures_t *textures)
{
    set_texture(&(decor->element), textures->road);
    return;
}
