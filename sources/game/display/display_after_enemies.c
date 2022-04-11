/*
** EPITECH PROJECT, 2022
** display_base.c
** File description:
** display_base
*/

#include "my_structures.h"

void display_after_enemies(scenes_t *scenes)
{
    sfRenderWindow_drawSprite(scenes->manager->window,
    scenes->game->decor->spawner->element, NULL);
    sfRenderWindow_drawSprite(scenes->manager->window,
    scenes->game->decor->base->element, NULL);
    sfRenderWindow_drawSprite(scenes->manager->window,
    scenes->game->decor->base->life_bar, NULL);
}
