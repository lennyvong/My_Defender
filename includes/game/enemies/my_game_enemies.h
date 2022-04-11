/*
** EPITECH PROJECT, 2022
** my_game_ennemies.h
** File description:
** my_game_ennemies
*/

#ifndef MY_GAME_ENNEMIES_H_
    #define MY_GAME_ENNEMIES_H_
#include <SFML/Graphics.h>

typedef struct game_enemy_s game_enemy_t;
typedef struct manager_s manager_t;
typedef struct maps_s maps_t;
typedef struct tab_enemies_s tab_enemies_t;
typedef struct game_scene_s game_scene_t;
typedef struct game_textures_s game_textures_t;

/* SOLDIER */
void my_soldier(game_enemy_t *enemy, manager_t *manager, game_scene_t *game
, tab_enemies_t *tab);
void preset_soldier(game_enemy_t *enemy, int y, int x,
game_textures_t *textures);
/* TANK */
void my_tank(game_enemy_t *enemy, manager_t *manager, game_scene_t *game
, tab_enemies_t *tab);
void preset_tank(game_enemy_t *enemy, int y, int x, game_textures_t *textures);
#endif /* !MY_GAME_ENNEMIES_H_ */
