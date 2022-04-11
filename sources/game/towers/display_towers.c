/*
** EPITECH PROJECT, 2022
** display_towers.c
** File description:
** display_towers
*/

#include "game/towers/my_shot_towers.h"
#include "game/towers/my_towers.h"
#include "my_structures.h"
#include "my_macro.h"

void display_towers(scenes_t *scenes)
{
    for (int i = 0 ; i != scenes->game->towers->nb_tower; i++) {
        if (scenes->game->towers->tower_archery[i]->statement == VISIBLE) {
            my_towers(scenes, scenes->game->towers->tower_archery[i]);
            tower_shot(scenes->game, scenes->game->ennemies->soldiers, i);
            tower_shot_tanks(scenes->game, scenes->game->ennemies->tanks, i);
        }
    }
    return;
}
