/*
** EPITECH PROJECT, 2022
** tank.c
** File description:
** tank
*/

#include <stdlib.h>
#include "my_macro.h"
#include "my_structures.h"
#include "my_lib.h"
#include "game/enemies/my_enemies_deplacements.h"
#include "game/enemies/my_generator_functions.h"

void preset_tankt_two(game_enemy_t *enemy, int y, int x,
game_textures_t *texture)
{
    set_texture(&(enemy->attack), texture->archer_attack);
    set_texture(&(enemy->enemy), texture->tank);
    set_texture(&(enemy->life_bar), texture->life_bar);
    sfSprite_setPosition(enemy->enemy, (sfVector2f) {enemy->x, enemy->y});
    sfSprite_setPosition(enemy->life_bar, (sfVector2f) {enemy->x - 25, enemy->y});
    sfSprite_setTextureRect(enemy->enemy, enemy->rect);
    sfSprite_setTextureRect(enemy->attack, enemy->rect_attack);
    sfSprite_setTextureRect(enemy->life_bar, enemy->rect_life);
    sfSprite_scale(enemy->enemy, (sfVector2f) {0.25, 0.25});
    sfSprite_scale(enemy->life_bar, (sfVector2f) {0.10, 0.10});
}

void preset_tank(game_enemy_t *enemy, int y, int x, game_textures_t *texture)
{
    enemy->clock_attack = sfClock_create();
    enemy->clock = sfClock_create();
    enemy->y = (y * 100) - 125;
    enemy->x = (x * 100);
    enemy->y_map = y;
    enemy->x_map = x;
    enemy->id = 'T';
    enemy->count_move = 0;
    enemy->max_move = 0;
    enemy->seconds = 0;
    enemy->seconds_attack = 0;
    enemy->statement = NO_MOVE;
    enemy->direction_spawn = malloc(sizeof(int) * 4 + 1);
    enemy->direction_spawn[0] = -1;
    enemy->rect = get_rect(0, 0, 840, 859);
    enemy->rect_life = get_rect(0, 0, 1000, 1000);
    enemy->rect_attack = get_rect(0, 0, 128, 91);
    enemy->action = MOVING;
    enemy->base = NOT_HERE;
    enemy->attacked = NOT_ATTACKED;
    enemy->life = 500;
    preset_tankt_two(enemy, y, x, texture);
    return;
}

void my_tank(game_enemy_t *enemy, manager_t *manager, game_scene_t *game
, tab_enemies_t *tab)
{
    if (enemy->action == MOVING) {
        enemy->time = sfClock_getElapsedTime(enemy->clock);
        enemy->seconds = enemy->time.microseconds / 1000000.0f;
        if (enemy->seconds > 0.1f) {
            identify_move(game->decor->base, enemy,
            tab, game->maps);
            sfSprite_setTextureRect(enemy->enemy, enemy->rect);
            sfClock_restart(enemy->clock);
        }
        sfSprite_setPosition(enemy->life_bar,
        (sfVector2f) {enemy->x + 85, enemy->y + 10});
        sfSprite_setPosition(enemy->enemy, (sfVector2f) {enemy->x, enemy->y});
        sfRenderWindow_drawSprite(manager->window, enemy->life_bar, NULL);
        sfRenderWindow_drawSprite(manager->window, enemy->enemy, NULL);
        if (enemy->attacked == ATTACKED) {
            enemy->time_attack = sfClock_getElapsedTime(enemy->clock_attack);
            enemy->seconds_attack = enemy->time_attack.microseconds / 1000000.0f;
            if (enemy->seconds_attack > 0.9f) {
                move_rect(&(enemy->rect_attack), 128, 512, 0);
                sfSprite_setTextureRect(enemy->attack, enemy->rect_attack);
                sfClock_restart(enemy->clock_attack);
            }
            sfSprite_setPosition(enemy->attack, (sfVector2f) {enemy->x + 35, enemy->y});
            sfRenderWindow_drawSprite(manager->window, enemy->attack, NULL);
            if (enemy->life <= 0) {
                sfSprite_setPosition(enemy->enemy,
                (sfVector2f) {game->maps->y_spawner * 100, game->maps->x_spawner * 100});
                enemy->action = NOT_MOVING;
                enemy->attacked = NOT_ATTACKED;
                game->ennemies->spawn_tanks->nb_killed += 1;
                sfClock_restart(enemy->clock_attack);
                game->nb += 15;
                return;
            }
        }
    }
    return;
}
