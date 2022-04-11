/*
** EPITECH PROJECT, 2022
** my_defender
** File description:
** all_move
*/

#include "my_structures.h"
#include "my_macro.h"
#include "game/enemies/my_generator_functions.h"
#include "my_lib.h"

void right_direction(game_enemy_t *enemy, maps_t *maps,
tab_enemies_t *tab)
{
    if (maps->map_use[enemy->y_map + 1][enemy->x_map] == 'R')
        add_tab_int(enemy->direction_spawn, BOT);
    if (maps->map_use[enemy->y_map - 1][enemy->x_map] == 'R')
        add_tab_int(enemy->direction_spawn, TOP);
    if (maps->map_use[enemy->y_map][enemy->x_map + 1] == 'R')
        add_tab_int(enemy->direction_spawn, RIGHT);
    if (maps->map_use[enemy->y_map][enemy->x_map + 1] == 'B') {
        add_tab_int(enemy->direction_spawn, BASE);
        add_tab_int(enemy->direction_spawn, RIGHT);
        random_move(enemy, maps, tab, RIGHT);
        return;
    }
    random_move(enemy, maps, tab, 0);
    return;
}

void left_direction(game_enemy_t *enemy, maps_t *maps, tab_enemies_t *tab)
{
    if (maps->map_use[enemy->y_map + 1][enemy->x_map] == 'R')
        add_tab_int(enemy->direction_spawn, BOT);
    if (maps->map_use[enemy->y_map - 1][enemy->x_map] == 'R')
        add_tab_int(enemy->direction_spawn, TOP);
    if (maps->map_use[enemy->y_map][enemy->x_map - 1] == 'R')
        add_tab_int(enemy->direction_spawn, LEFT);
    if (maps->map_use[enemy->y_map][enemy->x_map - 1] == 'B') {
        add_tab_int(enemy->direction_spawn, BASE);
        add_tab_int(enemy->direction_spawn, LEFT);
        random_move(enemy, maps, tab, LEFT);
        return;
    }
    random_move(enemy, maps, tab, 0);
    return;
}

void bot_direction(game_enemy_t *enemy, maps_t *maps, tab_enemies_t *tab)
{
    if (maps->map_use[enemy->y_map][enemy->x_map + 1] == 'R')
        add_tab_int(enemy->direction_spawn, RIGHT);
    if (maps->map_use[enemy->y_map][enemy->x_map - 1] == 'R')
        add_tab_int(enemy->direction_spawn, LEFT);
    if (maps->map_use[enemy->y_map + 1][enemy->x_map] == 'R')
        add_tab_int(enemy->direction_spawn, BOT);
    if (maps->map_use[enemy->y_map + 1][enemy->x_map] == 'B') {
        add_tab_int(enemy->direction_spawn, BASE);
        add_tab_int(enemy->direction_spawn, BOT);
        random_move(enemy, maps, tab, BOT);
        return;
    }
    random_move(enemy, maps, tab, 0);
    return;
}

void top_direction(game_enemy_t *enemy, maps_t *maps, tab_enemies_t *tab)
{
    if (maps->map_use[enemy->y_map][enemy->x_map + 1] == 'R')
        add_tab_int(enemy->direction_spawn, RIGHT);
    if (maps->map_use[enemy->y_map][enemy->x_map - 1] == 'R')
        add_tab_int(enemy->direction_spawn, LEFT);
    if (maps->map_use[enemy->y_map - 1][enemy->x_map] == 'R')
        add_tab_int(enemy->direction_spawn, TOP);
    if (maps->map_use[enemy->y_map - 1][enemy->x_map] == 'B') {
        add_tab_int(enemy->direction_spawn, BASE);
        add_tab_int(enemy->direction_spawn, TOP);
        random_move(enemy, maps, tab, TOP);
        return;
    }
    random_move(enemy, maps, tab, 0);
    return;
}
