/*
** EPITECH PROJECT, 2022
** my_game_decor.h
** File description:
** my_game_decor
*/

#ifndef MY_GAME_DECOR_H_
    #define MY_GAME_DECOR_H_

typedef struct maps_s maps_t;
typedef struct game_scene_s game_scene_t;
typedef struct map_info_s map_info_t;
typedef struct manager_s manager_t;
typedef struct game_textures_s game_textures_t;
typedef struct game_elements_s game_elements_t;

void malloc_elements(game_scene_t *game);
void preset_box(game_elements_t *decor, game_textures_t *textures);
void preset_grass(game_elements_t *decor, game_textures_t *textures);
void preset_road(game_elements_t *decor, game_textures_t *textures);
void preset_rock(game_elements_t *decor, game_textures_t *textures);
void preset_spawner(game_elements_t *decor, game_textures_t *textures, int y,
int x);
void set_decor(maps_t *maps, game_scene_t *game);
void set_money(game_scene_t *game);
void display_decor(map_info_t *info, game_scene_t *game, manager_t *manager);
void display_money(manager_t *manager, game_scene_t *game);
#endif /* !MY_GAME_DECOR_H_ */
