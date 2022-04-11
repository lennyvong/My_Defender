/*
** EPITECH PROJECT, 2022
** box.c
** File description:
** box
*/

#include "my_structures.h"
#include "my_lib.h"

void preset_box(game_elements_t*decor, game_textures_t *textures)
{
    set_texture(&(decor->element), textures->box);
    sfSprite_scale(decor->element, (sfVector2f) {0.5, 0.5});
    return;
}
