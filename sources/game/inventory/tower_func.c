/*
** EPITECH PROJECT, 2022
** my_defender
** File description:
** tower_func
*/

#include "my_structures.h"
#include "my_macro.h"
#include "my_lib.h"

int check_in_rect(sfVector2f pos, sfVector2i pos_mouse);

void change_tower(game_scene_t *game, towers_elements_t *tower,int id)
{
    switch (id) {
    case 1:
        tower->rect = get_rect(0, 0, 128, 126);
        break;
    case 2:
        tower->rect = get_rect(0, 256, 128, 126);
        break;
    case 3:
        tower->rect = get_rect(0, 128, 128, 126);
        break;
    case 4:
        tower->rect = get_rect(0, 384, 128, 126);
        break;
    }
    sfSprite_setTextureRect(tower->tower, tower->rect);
    tower->id = id;
    return;
}

void place_tower(manager_t *manager, game_scene_t *game)
{
    sfVector2f pos;
    for (int i = 0; i != game->towers->nb_tower; i++) {
        pos.x = ((float)game->towers->tower_archery[i]->x - 1) * 128;
        pos.y = ((float)game->towers->tower_archery[i]->y - 1) * 128;
        if (manager->event.type == sfEvtMouseButtonPressed
        && manager->event.mouseButton.button == sfMouseLeft
        && check_in_rect(pos, manager->mouse.mouse) == 1
        && manager->mouse.id != 0) {
            game->towers->tower_archery[i]->statement = VISIBLE;
            manager->mouse.id = 0;
            change_tower(game, game->towers->tower_archery[i],
            game->inventory[manager->mouse.inv_idx]->id);
            game->inventory[manager->mouse.inv_idx]->id = 0;
            sfRectangleShape_setFillColor(game->inventory
            [manager->mouse.inv_idx]->rect, sfTransparent);
            break;
        }
    }
}
