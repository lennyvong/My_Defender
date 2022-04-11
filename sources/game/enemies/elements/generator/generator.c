/*
** EPITECH PROJECT, 2022
** generator.c
** File description:
** generator
*/

#include <stdlib.h>
#include "my_structures.h"
#include "my_macro.h"
#include "game/enemies/my_enemies_deplacements.h"
#include "my_lib.h"

int find_function(game_enemy_t *enemy, tab_enemies_t *tab)
{
    for (int i = 0; tab[i].flag != '\0'; i++)
        if (tab[i].flag == enemy->id)
            return (i);
    return (-1);
}

void identify_move(game_elements_t *base, game_enemy_t *enemy,
tab_enemies_t *tab, maps_t *maps)
{
    if (enemy->base == HERE && enemy->count_move == enemy->max_move) {
        sfSprite_setPosition(enemy->enemy,
        (sfVector2f) {maps->y_spawner * 100, maps->x_spawner * 100});
        enemy->action = NOT_MOVING;
        if (enemy->id == 'T') {
            move_rect_minus(&(base->rect_life), -100, 0);
            sfSprite_setTextureRect(base->life_bar, base->rect_life);
            base->life -= 100;
        }
        if (enemy->id == 'S') {
            move_rect_minus(&(base->rect_life), -25, 0);
            sfSprite_setTextureRect(base->life_bar, base->rect_life);
            base->life -= 25;
        }
        return;
    }
    if (enemy->count_move == enemy->max_move) {
        which_move(enemy, maps, tab);
        if (enemy->id == 'T')
            enemy->max_move = 25;
        if (enemy->id == 'S')
            enemy->max_move = 25 + rand() % 3;
        enemy->count_move = 0;
    }
    tab[find_function(enemy, tab)].move(enemy, enemy->position);
    return;
}

void random_move(game_enemy_t *enemy, maps_t *maps, tab_enemies_t *tab,
int position)
{
    int pos = 0;
    int len = 0;

    for (; enemy->direction_spawn[len] != -1; len += 1);
    if (enemy->direction_spawn[len - len] == BASE) {
        tab[find_function(enemy, tab)].move(enemy, position);
        map_position_move(enemy, position);
        enemy->position = position;
        enemy->base = HERE;
        return;
    }
    pos = rand() % len;
    tab[find_function(enemy, tab)].move(enemy, enemy->direction_spawn[pos]);
    map_position_move(enemy, enemy->direction_spawn[pos]);
    enemy->position = enemy->direction_spawn[pos];
    return;
}
