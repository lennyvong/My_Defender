/*
** EPITECH PROJECT, 2022
** set_towers.c
** File description:
** set_towers
*/

#include <stdlib.h>
#include "my_structures.h"
#include "game/towers/my_towers.h"

static void malloc_tower(towers_t *tower, map_info_t *info)
{
    tower->tower_archery = malloc(sizeof(towers_elements_t)
    * info->grass);
    return;
}

static void find_place(game_scene_t *game, int y, int *i)
{
    for (int x = 1; game->maps->map_use[y][x] != '#'; x++) {
        if (game->maps->map_use[y][x] == ' ') {
            game->towers->tower_archery[*i] = malloc(sizeof
            (towers_elements_t));
            preset_tower(game->towers->tower_archery[*i], y, x,
            game->texture->tower_floor);
            *i += 1;
        }
    }
    return;
}

void set_towers(scenes_t *scenes)
{
    scenes->game->towers = malloc(sizeof(towers_t));
    scenes->game->towers->nb_tower = 0;
    malloc_tower(scenes->game->towers, scenes->game->info);
    for (int y = 0; scenes->game->maps->map_use[y] != NULL; y++)
        find_place(scenes->game, y, &scenes->game->towers->nb_tower);
}
