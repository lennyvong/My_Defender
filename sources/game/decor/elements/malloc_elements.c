/*
** EPITECH PROJECT, 2022
** malloc_elements.c
** File description:
** malloc_elements
*/

#include <stdlib.h>
#include "my_structures.h"

void malloc_elements(game_scene_t *game)
{
    game->decor->index = malloc(sizeof(index_decor_t));
    for (int i = 0; i != game->info->grass; i++)
        game->decor->grass[i] = malloc(sizeof(game_elements_t));
    for (int i = 0; i != game->info->road; i++)
        game->decor->road[i] = malloc(sizeof(game_elements_t));
    for (int i = 0; i != game->info->rock; i++)
        game->decor->rock[i] = malloc(sizeof(game_elements_t));
    for (int i = 0; i != game->info->box; i++)
        game->decor->box[i] = malloc(sizeof(game_elements_t));
    for (int i = 0; i != game->info->floor; i++)
        game->decor->floor[i] = malloc(sizeof(game_elements_t));
    game->decor->spawner = malloc(sizeof(game_elements_t));
    game->decor->base = malloc(sizeof(game_elements_t));
    return;
}
