/*
** EPITECH PROJECT, 2022
** my_defender
** File description:
** my_shop
*/

#include "my_structures.h"

void check_which_tower(game_scene_t *game, manager_t *manager);

static void set_price(scenes_t *scenes)
{
    int a = 0;

    for (int i = 1; i != 4; i++) {
        sfText_setPosition
        (scenes->game->shop[i]->price, (sfVector2f) {1360 + a, 376});
        a += 130;
    }
    sfText_setPosition
    (scenes->game->shop[4]->price, (sfVector2f) {1360, 538});
    sfText_setPosition
    (scenes->game->shop[5]->price, (sfVector2f) {1620, 538});
    sfText_setPosition
    (scenes->game->shop[6]->price, (sfVector2f) {1800, 498});
}

static void set_in_shop(scenes_t *scenes)
{
    int a = 0;

    sfRectangleShape_setPosition
    (scenes->game->shop[0]->rect, (sfVector2f) {1240, 150});
    for (int i = 1; i != 4; i++) {
        scenes->game->shop[i]->position = (sfVector2f) {1335 + a, 260};
        sfRectangleShape_setPosition
        (scenes->game->shop[i]->rect, (sfVector2f) {1335 + a, 260});
        a += 130;
    }
    scenes->game->shop[4]->position = (sfVector2f) {1335, 420};
    scenes->game->shop[5]->position = (sfVector2f) {1595, 420};
    scenes->game->shop[6]->position = (sfVector2f) {1695, 360};
    sfRectangleShape_setPosition
    (scenes->game->shop[4]->rect, (sfVector2f) {1335, 420});
    sfRectangleShape_setPosition
    (scenes->game->shop[5]->rect, (sfVector2f) {1595, 420});
    sfRectangleShape_setPosition
    (scenes->game->shop[6]->rect, (sfVector2f) {1765, 255});
    set_price(scenes);
}

static void go_in_shop(scenes_t *scenes, manager_t *manager)
{
    if (scenes->manager->event.type == sfEvtMouseButtonPressed
    && scenes->game->shopping == 0 && manager->event.mouseButton.x >= 1870
    && manager->event.mouseButton.y >= 350
    && manager->event.mouseButton.y <= 530) {
        scenes->game->shopping = 1;
        set_in_shop(scenes);
    }
}

void shop_zone(scenes_t *scenes, manager_t *manager)
{
    go_in_shop(scenes, manager);
    if (scenes->manager->event.type == sfEvtMouseButtonPressed
    && scenes->game->shopping == 1 && manager->event.mouseButton.x >= 1880
    && manager->event.mouseButton.y >= 190
    && manager->event.mouseButton.y <= 255) {
        scenes->game->shopping = 0;
        sfRectangleShape_setPosition
        (scenes->game->shop[0]->rect, (sfVector2f) {1870, 150});
        for (int i = 1; i != 7; i++) {
            sfRectangleShape_setPosition
            (scenes->game->shop[i]->rect, (sfVector2f) {1970, 150});
            sfText_setPosition
            (scenes->game->shop[i]->price, (sfVector2f) {1970, 150});
        }
        sfRectangleShape_setFillColor
        (scenes->game->shop[6]->rect, sfTransparent);
    } else if (scenes->manager->event.type == sfEvtMouseButtonPressed
        && scenes->game->shopping == 1)
        check_which_tower(scenes->game, manager);
}
