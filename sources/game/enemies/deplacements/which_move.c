/*
** EPITECH PROJECT, 2022
** which_move.c
** File description:
** which_move
*/

#include <stdlib.h>
#include "my_structures.h"
#include "my_macro.h"
#include "my_lib.h"
#include "game/enemies/my_generator_functions.h"

void soldier_move(game_enemy_t *enemy, int move);
void map_position_move(game_enemy_t *enemy, int position);
void top_direction(game_enemy_t *enemy, maps_t *maps, tab_enemies_t *tab);
void bot_direction(game_enemy_t *enemy, maps_t *maps, tab_enemies_t *tab);
void right_direction(game_enemy_t *enemy, maps_t *maps, tab_enemies_t *tab);
void left_direction(game_enemy_t *enemy, maps_t *maps, tab_enemies_t *tab);

static int check_base(game_enemy_t *enemy, maps_t *maps)
{
    if (maps->map_use[enemy->y_map][enemy->x_map] == 'B')
        return (1);
    return (0);
}

static void first_move(game_enemy_t *enemy, maps_t *maps, tab_enemies_t *tab)
{
    if (maps->map_use[enemy->y_map][enemy->x_map + 1] == 'R') {
        add_tab_int(enemy->direction_spawn, RIGHT);
    }
    if (maps->map_use[enemy->y_map][enemy->x_map - 1] == 'R')
        add_tab_int(enemy->direction_spawn, LEFT);
    if (maps->map_use[enemy->y_map + 1][enemy->x_map] == 'R')
        add_tab_int(enemy->direction_spawn, BOT);
    if (maps->map_use[enemy->y_map - 1][enemy->x_map] == 'R')
        add_tab_int(enemy->direction_spawn, TOP);
    random_move(enemy, maps, tab, 0);
    return;
}

void which_move(game_enemy_t *enemy, maps_t *maps, tab_enemies_t *tab)
{
    if (enemy->statement == NO_MOVE) {
        first_move(enemy, maps, tab);
        return;
    }
    enemy->direction_spawn = malloc(sizeof(int) * 4 + 1);
    enemy->direction_spawn[0] = -1;
    switch (enemy->statement) {
    case RIGHT:
        right_direction(enemy, maps, tab);
        break;
    case LEFT:
        left_direction(enemy, maps, tab);
        break;
    case BOT:
        bot_direction(enemy, maps, tab);
        break;
    case TOP:
        top_direction(enemy, maps, tab);
        break;
    }
}
