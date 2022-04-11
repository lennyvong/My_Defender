/*
** EPITECH PROJECT, 2022
** tower_archery.c
** File description:
** tower_archery
*/

#include "my_structures.h"
#include "my_macro.h"
#include "my_lib.h"

void preset_tower(towers_elements_t *tower, int y, int x, sfTexture *texture)
{
    tower->clock = sfClock_create();
    tower->y = y;
    tower->x = x;
    tower->id = '0';
    tower->statement = INVISIBLE;
    set_texture(&(tower->tower), texture);
    sfSprite_setPosition(tower->tower, (sfVector2f)
    {(128 * (tower->x - 1)) + 18, (128 * (tower->y - 1)) + 19});
    sfSprite_scale(tower->tower, (sfVector2f) {0.75, 0.75});
    return;
}

void my_towers(scenes_t *scenes, towers_elements_t *tower)
{
    if (tower->statement == VISIBLE) {
        sfRenderWindow_drawSprite
        (scenes->manager->window, tower->tower, NULL);
    }
    return;
}
