/*
** EPITECH PROJECT, 2022
** soldier_move.c
** File description:
** soldier_move
*/

#include "my_structures.h"
#include "my_lib.h"
#include "my_macro.h"

static void soldier_move_two(game_enemy_t *enemy, int move)
{
    if (move == BOT) {
        if (enemy->rect.left < 1200 || enemy->rect.left > 2000)
            enemy->rect.left = 1200;
        move_rect(&enemy->rect, 200, 1600, 1200);
        sfSprite_setPosition(enemy->enemy,
        (sfVector2f) {enemy->x, enemy->y + 1});
        enemy->y += 5;
        enemy->statement = BOT;
    }
    if (move == LEFT) {
        if (enemy->rect.left < 1800 || enemy->rect.left > 2200)
            enemy->rect.left = 1800;
        move_rect(&enemy->rect, 200, 2200, 1800);
        sfSprite_setPosition(enemy->enemy,
        (sfVector2f) {enemy->x - 1, enemy->y});
        enemy->x -= 5;
        enemy->statement = LEFT;
    }
}

void soldier_move(game_enemy_t *enemy, int move)
{
    if (move == TOP) {
        if (enemy->rect.left < 0 || enemy->rect.left > 400)
            enemy->rect.left = 0;
        move_rect(&enemy->rect, 200, 400, 0);
        sfSprite_setPosition(enemy->enemy,
        (sfVector2f) {enemy->x, enemy->y - 1});
        enemy->y -= 5;
        enemy->statement = TOP;
    }
    if (move == RIGHT) {
        if (enemy->rect.left < 600 || enemy->rect.left > 1000)
            enemy->rect.left = 600;
        move_rect(&enemy->rect, 200, 1000, 600);
        sfSprite_setPosition(enemy->enemy,
        (sfVector2f) {enemy->x + 1, enemy->y});
        enemy->x += 5;
        enemy->statement = RIGHT;
    }
    soldier_move_two(enemy, move);
    enemy->count_move += 1;
}
