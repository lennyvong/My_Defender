/*
** EPITECH PROJECT, 2022
** smoke.c
** File description:
** smoke
*/

#include "my_structures.h"

void move_rect(sfIntRect *rect, int offset, int max_value);

void init_smoke(smoke_t *smoke)
{
    smoke->texture_smoke = sfTexture_createFromFile("assets/smoke.png", NULL);
    smoke->sprite_smoke = sfSprite_create();
    smoke->rect_smoke.top = 0;
    smoke->rect_smoke.left = 0;
    smoke->rect_smoke.width = 600;
    smoke->rect_smoke.height = 375;
    sfSprite_setTexture(smoke->sprite_smoke, smoke->texture_smoke, sfFalse);
    sfSprite_setPosition(smoke->sprite_smoke, (sfVector2f) {150, 10});
    sfSprite_setScale(smoke->sprite_smoke, (sfVector2f) {2.3, 2.3});
    sfSprite_setTextureRect(smoke->sprite_smoke, smoke->rect_smoke);
}

void display_smoke(scenes_t *scenes)
{
    scenes->smoke->time_smoke =
    sfClock_getElapsedTime(scenes->smoke->clock_smoke);
    scenes->smoke->sec_smoke =
    scenes->smoke->time_smoke.microseconds / 1000000.0;
    if (scenes->smoke->sec_smoke > 0.1) {
        move_rect(&scenes->smoke->rect_smoke, 600, 5400);
        sfSprite_setTextureRect
        (scenes->smoke->sprite_smoke, scenes->smoke->rect_smoke);
        sfClock_restart(scenes->smoke->clock_smoke);
    }
    sfRenderWindow_drawSprite
    (scenes->manager->window, scenes->smoke->sprite_smoke, NULL);
}
