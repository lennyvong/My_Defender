/*
** EPITECH PROJECT, 2022
** tank_move.c
** File description:
** tank_move
*/

#include "my_structures.h"
#include "my_lib.h"
#include "my_macro.h"

static void tank_move_two(game_enemy_t *enemy, int move)
{
    if (move == BOT) {
        enemy->rect.left = 840;
        sfSprite_setPosition(enemy->enemy,
        (sfVector2f) {enemy->x, enemy->y + 1});
        enemy->y += 5;
        enemy->statement = BOT;
    }
    if (move == LEFT) {
        enemy->rect.left = 1680;
        sfSprite_setPosition(enemy->enemy,
        (sfVector2f) {enemy->x - 1, enemy->y});
        enemy->x -= 5;
        enemy->statement = LEFT;
    }
}

void tank_move(game_enemy_t *enemy, int move)
{
    if (move == TOP) {
        enemy->rect.left = 2520;
        sfSprite_setPosition(enemy->enemy,
        (sfVector2f) {enemy->x, enemy->y - 1});
        enemy->y -= 5;
        enemy->statement = TOP;
    }
    if (move == RIGHT) {
        enemy->rect.left = 0;
        sfSprite_setPosition(enemy->enemy,
        (sfVector2f) {enemy->x + 1, enemy->y});
        enemy->x += 5;
        enemy->statement = RIGHT;
    }
    tank_move_two(enemy, move);
    enemy->count_move += 1;
}
