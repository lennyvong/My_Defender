/*
** EPITECH PROJECT, 2022
** spawner.c
** File description:
** spawner
*/

#include "my_structures.h"
#include "my_lib.h"

void preset_spawner(game_elements_t *decor, game_textures_t *textures, int y
, int x)
{
    set_texture(&(decor->element), textures->spawner);
    set_texture(&(decor->life_bar), textures->life_bar);
    decor->rect_life = get_rect(0, 0, 1000, 1000);
    sfSprite_setTextureRect(decor->life_bar, decor->rect_life);
    sfSprite_setPosition(decor->element,
    (sfVector2f) {128 * (x - 1) - 187, 128 * (y - 1) - 100});
    sfSprite_setPosition(decor->life_bar,
    (sfVector2f) {128 * (x - 1) + 13, 128 * (y - 1) - 15});
    decor->life = 1000;
    sfSprite_scale(decor->life_bar, (sfVector2f) {0.10, 0.10});
    return;
}
