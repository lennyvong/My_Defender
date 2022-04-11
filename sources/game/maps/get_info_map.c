/*
** EPITECH PROJECT, 2022
** get_info_map.c
** File description:
** get_info_map
*/

#include <stdlib.h>
#include "my_structures.h"

static void identify(map_info_t *info, char c)
{
    if (c == ' ' || c == 'O' || c == 'X' || c == 'T')
        info->grass += 1;
    if (c == 'R' || c == 'S' || c == 'B')
        info->road += 1;
    if (c == 'O')
        info->rock += 1;
    if (c == 'X')
        info->box += 1;
    if (c == 'T')
        info->floor += 1;
}

static int find_spawner(maps_t *maps, char *line)
{
    for (int x = 0; line[x] != '\0'; x++)
        if (line[x] == 'S') {
            maps->x_spawner = x;
            return (1);
        }
    return (0);
}

void get_info_map(maps_t *maps, game_scene_t *game, int i_map)
{
    game->info = malloc(sizeof(map_info_t));
    game->info->grass = 0;
    game->info->road = 0;
    game->info->rock = 0;
    game->info->box = 0;
    game->info->floor = 0;
    for (int y = 0; maps->map_use[y] != NULL; y++)
        for (int x = 0; maps->map_use[y][x] != '\0'; x++)
            identify(game->info, maps->map_use[y][x]);
    for (int y = 0; maps->map_use[y] != NULL; y++)
        if (find_spawner(maps, maps->map_use[y]) == 1)
            maps->y_spawner = y;
    return;
}
