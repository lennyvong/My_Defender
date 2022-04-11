/*
** EPITECH PROJECT, 2022
** rock.c
** File description:
** rock
*/

#include "my_structures.h"
#include "my_lib.h"

void preset_rock(game_elements_t *decor, game_textures_t *textures)
{
    set_texture(&(decor->element), textures->rock);
    return;
}
