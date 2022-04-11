/*
** EPITECH PROJECT, 2022
** display_enemies.c
** File description:
** display_enemies
*/

#include "my_structures.h"
#include "game/enemies/my_game_enemies.h"

static void display_soldiers(manager_t *manager, game_scene_t *game,
tab_enemies_t *tab)
{
    for (int i = 0; i != game->ennemies->spawn_soldiers->i_count; i++)
        my_soldier(game->ennemies->soldiers[i], manager, game, tab);
    if (game->ennemies->spawn_soldiers->i_count != game->info->road * 10) {
        game->ennemies->spawn_soldiers->time
        = sfClock_getElapsedTime(game->ennemies->spawn_soldiers->clock);
        game->ennemies->spawn_soldiers->seconds
        = game->ennemies->spawn_soldiers->time.microseconds / 1000000.0f;
        if (game->ennemies->spawn_soldiers->seconds > 1.5f) {
            game->ennemies->spawn_soldiers->i_count += 1;
            sfClock_restart(game->ennemies->spawn_soldiers->clock);
        }
    }
}

static void display_tanks(manager_t *manager, game_scene_t *game,
tab_enemies_t *tab)
{
    for (int i = 0; i != game->ennemies->spawn_tanks->i_count; i++)
        my_tank(game->ennemies->tanks[i], manager, game, tab);
    if (game->ennemies->spawn_tanks->i_count != game->info->road / 2) {
        game->ennemies->spawn_tanks->time
        = sfClock_getElapsedTime(game->ennemies->spawn_tanks->clock);
        game->ennemies->spawn_tanks->seconds
        = game->ennemies->spawn_tanks->time.microseconds / 1000000.0f;
        if (game->ennemies->spawn_tanks->seconds > 15.0f) {
            game->ennemies->spawn_tanks->i_count += 1;
            sfClock_restart(game->ennemies->spawn_tanks->clock);
        }
    }
}

void display_enemies(manager_t *manager, game_scene_t *game, tab_enemies_t *tab)
{
    display_soldiers(manager, game, tab);
    display_tanks(manager, game, tab);
}
