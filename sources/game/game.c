/*
** EPITECH PROJECT, 2022
** game.c
** File description:
** game
*/

#include <stdlib.h>
#include <time.h>
#include "my_structures.h"
#include "game/my_game_decor.h"
#include "game/my_game_decor.h"
#include "game/enemies/my_game_enemies.h"
#include "game/enemies/my_enemies_deplacements.h"
#include "game/my_game.h"
#include "end_game/end_game.h"

void set_towers(scenes_t *scenes);
void display_towers(scenes_t *scenes);
void inventory_zone(scenes_t *scenes, manager_t *manager);
void shop_zone(scenes_t *scenes, manager_t *manager);
void display_all(scenes_t *scenes, tab_enemies_t *tab);

void analyse_events(scenes_t *scenes, manager_t *manager)
{
    if (manager->event.type == sfEvtKeyPressed
        && manager->event.key.code == sfKeyEscape)
        pause_menu(scenes, manager);
    inventory_zone(scenes, manager);
    shop_zone(scenes, manager);
    if (manager->event.type == sfEvtClosed)
        sfRenderWindow_close(manager->window);
}

static void set_spawn(enemies_t *enemies)
{
    enemies->spawn_soldiers = malloc(sizeof(spawn_enemies_t));
    enemies->spawn_tanks = malloc(sizeof(spawn_enemies_t));
    enemies->spawn_soldiers->clock = sfClock_create();
    enemies->spawn_soldiers->i_count = 1;
    enemies->spawn_tanks->clock = sfClock_create();
    enemies->spawn_tanks->i_count = 1;
    enemies->spawn_soldiers->nb_killed = 0;
    enemies->spawn_tanks->nb_killed = 0;
}

static void set_textures(game_scene_t *game)
{
    game->texture = malloc(sizeof(game_textures_t));
    game->texture->soldier = sfTexture_createFromFile
    ("assets/soldier.png", NULL);
    game->texture->tank = sfTexture_createFromFile
    ("assets/tank.png", NULL);
    game->texture->tower_floor = sfTexture_createFromFile
    ("assets/floor_tower.png", NULL);
    game->texture->life_bar = sfTexture_createFromFile
    ("assets/life_bar_1000.png", NULL);
    game->texture->box = sfTexture_createFromFile
    ("assets/box.png", NULL);
    game->texture->grass = sfTexture_createFromFile
    ("assets/grass.png", NULL);
    game->texture->road = sfTexture_createFromFile
    ("assets/dirt.png", NULL);
    game->texture->rock = sfTexture_createFromFile
    ("assets/rock.png", NULL);
    game->texture->spawner = sfTexture_createFromFile
    ("assets/spawner.png", NULL);
    game->texture->archer_attack = sfTexture_createFromFile
    ("assets/attack_archer.png", NULL);
    game->texture->fire_drag = sfTexture_createFromFile
    ("assets/fire_dragon.png", NULL);
    game->texture->ice_attack = sfTexture_createFromFile
    ("assets/ice.png", NULL);
    game->texture->fire_blue = sfTexture_createFromFile
    ("assets/fire_blue.png", NULL);
}

static void set_game(scenes_t *scenes, int i_map)
{
    scenes->endscene = 0;
    scenes->game->maps = malloc(sizeof(maps_t));
    scenes->game->decor = malloc(sizeof(decor_t));
    scenes->game->ennemies = malloc(sizeof(enemies_t));
    get_map(scenes->game, i_map);
    get_info_map(scenes->game->maps, scenes->game, i_map);
    malloc_elements(scenes->game);
    set_money(scenes->game);
    set_settings(scenes->pause);
    set_textures(scenes->game);
    set_decor(scenes->game->maps, scenes->game);
    set_enemies(scenes->game->ennemies, scenes->game->maps, scenes->game);
    set_spawn(scenes->game->ennemies);
    set_inventory(scenes, scenes->game);
    set_towers(scenes);
}

void play_game(scenes_t *scenes, int i_map)
{
    tab_enemies_t tab[] = {
        {&(soldier_move), 'S'},
        {&(tank_move), 'T'},
    };
    set_game(scenes, i_map);
    while (sfRenderWindow_isOpen(scenes->manager->window) &&
    scenes->mode >= 0) {
        sfRenderWindow_clear(scenes->manager->window, sfBlack);
        display_all(scenes, tab);
        while (sfRenderWindow_pollEvent(scenes->manager->window, &scenes->manager->event))
            analyse_events(scenes, scenes->manager);
        sfRenderWindow_display(scenes->manager->window);
    }
    return;
}