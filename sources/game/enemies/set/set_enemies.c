/*
** EPITECH PROJECT, 2022
** set_enemies.c
** File description:
** set_enemies
*/

#include <stdlib.h>
#include "game/enemies/my_game_enemies.h"
#include "my_structures.h"

static void which_enemy(game_scene_t *game, enemies_t *enemies, int y
, int x)
{
    for (int i = 0; i != game->info->road * 10; i++) {
        enemies->soldiers[i] = malloc(sizeof(game_enemy_t));
        preset_soldier(enemies->soldiers[i], y, x, game->texture);
    }
    for (int i = 0; i != game->info->road / 2; i++) {
        enemies->tanks[i] = malloc(sizeof(game_enemy_t));
        preset_tank(enemies->tanks[i], y, x, game->texture);
    }
}

static void find_spawner(enemies_t *enemies, maps_t *maps, game_scene_t *game
, int y)
{
    for (int x = 1; maps->map_use[y][x] != '#'; x++) {
        if (maps->map_use[y][x] == 'S') {
            which_enemy(game, enemies, y, x);
            return;
        }
    }
}

void set_enemies(enemies_t *enemies, maps_t *maps, game_scene_t *game)
{
    enemies->soldiers = malloc(sizeof(*enemies->soldiers)
    * game->info->road * 10);
    enemies->tanks = malloc(sizeof(*enemies->soldiers) *
    (game->info->road / 2));
    for (int y = 1; maps->map_use[y] != NULL; y++)
        find_spawner(enemies, maps, game, y);
}