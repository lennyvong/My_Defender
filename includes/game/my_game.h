/*
** EPITECH PROJECT, 2022
** my_game.h
** File description:
** my_game
*/

#ifndef MY_GAME_H_
    #define MY_GAME_H_

typedef struct game_scene_s game_scene_t;
typedef struct maps_s maps_t;
typedef struct enemies_s enemies_t;
typedef struct manager_s manager_t;

void set_enemies(enemies_t *enemies, maps_t *maps, game_scene_t *game);
void display_enemies(manager_t *manager, game_scene_t *game,
tab_enemies_t*tab);
void display_after_enemies(scenes_t *scenes);
void get_map(game_scene_t *game, int i_map);
void get_info_map(maps_t *maps, game_scene_t *game, int i_map);
void pause_menu(scenes_t *scenes, manager_t *manager);
void display_book(scenes_t *scenes, float speed);
void set_settings(game_pause_t *pause);
void set_inventory(scenes_t *scenes, game_scene_t *game);
#endif /* !MY_GAME_H_ */
