/*
** EPITECH PROJECT, 2022
** move.c
** File description:
** move
*/

#include <stdlib.h>
#include "my_structures.h"
#include "my_macro.h"

void map_position_move(game_enemy_t *enemy, int position)
{
    switch (position)
    {
    case RIGHT:
        enemy->x_map += 1;
        break;
    case LEFT:
        enemy->x_map -= 1;
        break;
    case TOP:
        enemy->y_map -= 1;
        break;
    case BOT:
        enemy->y_map += 1;
        break;
    default:
        break;
    }
    return;
}
