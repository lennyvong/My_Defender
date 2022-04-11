/*
** EPITECH PROJECT, 2022
** decor.c
** File description:
** decor
*/

#include <stdlib.h>
#include "game/my_game_decor.h"
#include "my_structures.h"

static void decor_position_two(game_scene_t *game, char c, int y, int x)
{
    if (c == 'O') {
        preset_rock
        (game->decor->rock[game->decor->index->rock], game->texture);
        sfSprite_setPosition
        (game->decor->rock[game->decor->index->rock]->element,
        (sfVector2f) {128 * (x - 1), 128 * (y - 1)});
        game->decor->index->rock += 1;
    }
    if (c == 'X') {
        preset_box(game->decor->box[game->decor->index->box], game->texture);
        sfSprite_setPosition
        (game->decor->box[game->decor->index->box]->element,
        (sfVector2f) {128 * (x - 1), 128 * (y - 1)});
        game->decor->index->box += 1;
    }
    if (c == 'S')
        preset_spawner(game->decor->spawner, game->texture, y, x);
    if (c == 'B')
        preset_spawner(game->decor->base, game->texture, y, x);
}

static void decor_position(game_scene_t *game, char c, int y, int x)
{
    if (c == ' ' || c == 'O' || c == 'X') {
        preset_grass
        (game->decor->grass[game->decor->index->grass], game->texture);
        sfSprite_setPosition
        (game->decor->grass[game->decor->index->grass]->element,
        (sfVector2f) {128 * (x - 1), 128 * (y - 1)});
        game->decor->index->grass += 1;
    }
    if (c == 'R' || c == 'S' || c == 'B') {
        preset_road
        (game->decor->road[game->decor->index->road], game->texture);
        sfSprite_setPosition
        (game->decor->road[game->decor->index->road]->element,
        (sfVector2f) {128 * (x - 1), 128 * (y - 1)});
        game->decor->index->road += 1;
    }
    decor_position_two(game, c, y, x);
}

void set_decor(maps_t *maps, game_scene_t *game)
{
    game->decor->index->grass = 0;
    game->decor->index->road = 0;
    game->decor->index->rock = 0;
    game->decor->index->box = 0;
    game->decor->index->floor = 0;
    for (int y = 1; maps->map_use[y] != NULL; y++)
        for (int x = 1; maps->map_use[y][x] != '#'; x++)
            decor_position(game, maps->map_use[y][x], y, x);
    return;
}

void display_decor(map_info_t *info, game_scene_t *game, manager_t *manager)
{
    for (int i = 0; i != info->grass; i++)
        sfRenderWindow_drawSprite
        (manager->window, game->decor->grass[i]->element, NULL);
    for (int i = 0; i != info->rock; i++)
        sfRenderWindow_drawSprite
        (manager->window, game->decor->rock[i]->element, NULL);
    for (int i = 0; i != info->box; i++)
        sfRenderWindow_drawSprite
        (manager->window, game->decor->box[i]->element, NULL);
    for (int i = 0; i != info->road; i++)
        sfRenderWindow_drawSprite
        (manager->window, game->decor->road[i]->element, NULL);
}