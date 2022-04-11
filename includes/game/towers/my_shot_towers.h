/*
** EPITECH PROJECT, 2022
** my_shot_tower.h
** File description:
** my_shot_towers
*/

#ifndef MY_SHOT_TOWERS_H_
    #define MY_SHOT_TOWERS_H_

typedef struct scenes_s scenes_t;
typedef struct game_enemy_s game_enemy_t;
typedef struct towers_elements_s towers_elements_t;
typedef struct maps_s maps_t;
typedef struct game_scene_s game_scene_t;
void tower_shot_tanks(game_scene_t *game, game_enemy_t **enemy, int i_towers);
void tower_shot(game_scene_t *game, game_enemy_t **enemy, int i_towers);
#endif /* !MY_SHOT_TOWERS_H_ */
