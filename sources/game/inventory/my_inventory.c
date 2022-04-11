/*
** EPITECH PROJECT, 2022
** my_defender
** File description:
** my_inventory
*/

#include "my_structures.h"
#include "my_macro.h"
#include "my_lib.h"

void place_tower(manager_t *manager, game_scene_t *game);

int check_in_rect(sfVector2f pos, sfVector2i pos_mouse)
{
    if ((float)pos_mouse.x >= pos.x - 100 && (float)pos_mouse.x <= pos.x + 100
        && (float)pos_mouse.y >= pos.y - 100
        && (float)pos_mouse.y <= pos.y + 100) {
        return (1);
    }
    return (0);
}

static void inventory_event2(game_scene_t *game, manager_t *manager)
{
    for (int i = 1; i != 9; i++)
        sfRectangleShape_setPosition(game->inventory[i]->rect,
        (sfVector2f) {612, 1080});
}

static void inventory_event(game_scene_t *game, manager_t *manager,
sfVector2f pos)
{
    for (int i = 1; i != 9; i++) {
        if (pos.x >= game->inventory[i]->position.x
        && pos.x <= game->inventory[i]->position.x + 82
        && pos.y >= game->inventory[i]->position.y
        && pos.y <= game->inventory[i]->position.y + 82) {
            manager->mouse.id = game->inventory[i]->id;
            manager->mouse.inv_idx = i;
            sfRectangleShape_setPosition(game->inventory[0]->rect,
            (sfVector2f) {570, 950});
            inventory_event2(game, manager);
            game->mode = 0;
        }
    }
}

static void out_inventory(scenes_t *scenes, manager_t *manager)
{
    sfVector2f pos = {0, 0};
    int a = 0;
    if (scenes->game->mode == 0 && manager->event.mouseMove.x >= 575 &&
        manager->event.mouseMove.x <= 1320 &&
        manager->event.mouseMove.y >= 1000) {
        scenes->game->mode = 1;
        sfRectangleShape_setPosition(scenes->game->inventory[0]->rect,
        (sfVector2f) {570, 700});
        for (int i = 1; i != 9; i++) {
            scenes->game->inventory[i]->position = (sfVector2f) {612 + a, 925};
            sfRectangleShape_setPosition(scenes->game->inventory[i]->rect,
            scenes->game->inventory[i]->position);
            a += 83;
        }
    }
    if (scenes->game->mode == 1 && manager->event.type
        == sfEvtMouseButtonPressed) {
        pos.x = manager->event.mouseButton.x;
        pos.y = manager->event.mouseButton.y;
        inventory_event(scenes->game, manager, pos);
    }
}

void inventory_zone(scenes_t *scenes, manager_t *manager)
{
    manager->mouse.mouse = sfMouse_getPositionRenderWindow(manager->window);
    out_inventory(scenes, manager);
    if ((scenes->game->mode == 1 && (manager->event.mouseMove.x <= 575 ||
        manager->event.mouseMove.x >= 1320) &&
        manager->event.mouseMove.y <= 1000) || manager->event.mouseMove.y <=
        750) {
        scenes->game->mode = 0;
        sfRectangleShape_setPosition(scenes->game->inventory[0]->rect,
        (sfVector2f) {570, 950});
        for (int i = 1; i != 9; i++)
            sfRectangleShape_setPosition(scenes->game->inventory[i]->rect,
            (sfVector2f) {612, 1080});
    }
    place_tower(manager, scenes->game);
}
