/*
** EPITECH PROJECT, 2022
** shot.c
** File description:
** shot
*/

#include <stdio.h>
#include "my_structures.h"
#include "my_macro.h"
#include "my_lib.h"

void tower_shot_tanks(game_scene_t *game, game_enemy_t **enemy, int i_towers)
{
for (int i_tanks = 0 + game->ennemies->spawn_tanks->nb_killed; i_tanks <=
    game->info->road / 2; i_tanks += 1) {
        if (i_tanks + game->ennemies->spawn_tanks->nb_killed < game->info->road / 2 &&
        game->towers->tower_archery[i_towers]->statement == VISIBLE &&
        enemy[i_tanks]->x_map <= game->towers->tower_archery[i_towers]->x + 1 &&
        enemy[i_tanks]->x_map >= game->towers->tower_archery[i_towers]->x - 1 &&
        enemy[i_tanks]->y_map <= game->towers->tower_archery[i_towers]->y + 1 &&
        enemy[i_tanks]->y_map >= game->towers->tower_archery[i_towers]->y - 1) {
            switch (game->towers->tower_archery[i_towers]->id) {
            case 1:
                set_texture(&(enemy[i_tanks]->attack),
                game->texture->archer_attack);
                break;
            case 2:
                set_texture(&(enemy[i_tanks]->attack),
                game->texture->fire_blue);
                break;
            case 3:
                set_texture(&(enemy[i_tanks]->attack),
                game->texture->ice_attack);
                enemy[i_tanks]->rect_attack = get_rect(0, 0, 128, 72);
                break;
            case 4:
                set_texture(&(enemy[i_tanks]->attack),
                game->texture->fire_drag);
                enemy[i_tanks]->rect_attack = get_rect(0, 0, 128, 96);
                break;
            }
            sfSprite_setTextureRect(enemy[i_tanks]->attack, enemy[i_tanks]->rect_attack);
            game->towers->tower_archery[i_towers]->time =
            sfClock_getElapsedTime(game->towers->tower_archery[i_towers]->clock);
            game->towers->tower_archery[i_towers]->seconds =
            game->towers->tower_archery[i_towers]->time.microseconds
            / 1000000.0f;
            if (game->towers->tower_archery[i_towers]->seconds > 0.5f) {
                enemy[i_tanks]->attacked = ATTACKED;
                switch (game->towers->tower_archery[i_towers]->id) {
                case 1:
                    enemy[i_tanks]->life -= 1;
                    move_rect_minus(&(enemy[i_tanks]->rect_life), -1 * 2, 0);
                    break;
                case 2:
                    enemy[i_tanks]->life -= 20;
                    move_rect_minus(&(enemy[i_tanks]->rect_life), -20 * 2, 0);
                    break;
                case 3:
                    enemy[i_tanks]->life -= 5;
                    move_rect_minus(&(enemy[i_tanks]->rect_life), -5 * 2,  0);
                    break;
                case 4:
                    enemy[i_tanks]->life -= 75;
                    move_rect_minus(&(enemy[i_tanks]->rect_life), -75 * 2, 0);
                    break;
                }
                sfSprite_setTextureRect(enemy[i_tanks]->life_bar, enemy[i_tanks]->rect_life);
                sfClock_restart(game->towers->tower_archery[i_towers]->clock);
            } else {
                enemy[i_tanks]->attacked = NOT_ATTACKED;
            }
        }
    }
    return;
}

void tower_shot(game_scene_t *game, game_enemy_t **enemy, int i_towers)
{
    for (int i_soldier = 0 + game->ennemies->spawn_soldiers->nb_killed; i_soldier <
    game->info->road * 10; i_soldier += 1) {
        if (i_soldier + game->ennemies->spawn_soldiers->nb_killed <=
        game->info->road * 10 && game->towers->tower_archery[i_towers]->statement == VISIBLE &&
        enemy[i_soldier]->x_map <= game->towers->tower_archery[i_towers]->x + 1 &&
        enemy[i_soldier]->x_map >= game->towers->tower_archery[i_towers]->x - 1 &&
        enemy[i_soldier]->y_map <= game->towers->tower_archery[i_towers]->y + 1 &&
        enemy[i_soldier]->y_map >= game->towers->tower_archery[i_towers]->y - 1) {
            switch (game->towers->tower_archery[i_towers]->id) {
            case 1:
                set_texture(&(enemy[i_soldier]->attack),
                game->texture->archer_attack);
                break;
            case 2:
                set_texture(&(enemy[i_soldier]->attack),
                game->texture->fire_blue);
                break;
            case 3:
                set_texture(&(enemy[i_soldier]->attack),
                game->texture->ice_attack);
                enemy[i_soldier]->rect_attack = get_rect(0, 0, 128, 72);
                break;
            case 4:
                set_texture(&(enemy[i_soldier]->attack),
                game->texture->fire_drag);
                enemy[i_soldier]->rect_attack = get_rect(0, 0, 128, 96);
                break;
            }
            sfSprite_setTextureRect(enemy[i_soldier]->attack, enemy[i_soldier]->rect_attack);
            game->towers->tower_archery[i_towers]->time =
            sfClock_getElapsedTime(game->towers->tower_archery[i_towers]->clock);
            game->towers->tower_archery[i_towers]->seconds =
            game->towers->tower_archery[i_towers]->time.microseconds
            / 1000000.0f;
            if (game->towers->tower_archery[i_towers]->seconds > 0.5f) {
                enemy[i_soldier]->attacked = ATTACKED;
                switch (game->towers->tower_archery[i_towers]->id) {
                case 1:
                    enemy[i_soldier]->life -= 1;
                    move_rect_minus(&(enemy[i_soldier]->rect_life), -200, 0);
                    break;
                case 2:
                    enemy[i_soldier]->life -= 20;
                    move_rect_minus(&(enemy[i_soldier]->rect_life), -1000, 0);
                    break;
                case 3:
                    enemy[i_soldier]->life -= 5;
                    move_rect_minus(&(enemy[i_soldier]->rect_life), -334, 0);
                    break;
                case 4:
                    enemy[i_soldier]->life -= 75;
                    move_rect_minus(&(enemy[i_soldier]->rect_life), -1000, 0);
                    break;
                }
                sfSprite_setTextureRect(enemy[i_soldier]->life_bar, enemy[i_soldier]->rect_life);
                sfClock_restart(game->towers->tower_archery[i_towers]->clock);
            } else {
                enemy[i_soldier]->attacked = NOT_ATTACKED;
            }
            break;
        }
    }
    return;
}