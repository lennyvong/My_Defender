/*
** EPITECH PROJECT, 2022
** my_soldiers_deplacement.h
** File description:
** my_soldier_deplacements
*/

#ifndef MY_SOLDIER_DEPLACEMENTS_H_
    #define MY_SOLDIER_DEPLACEMENTS_H_

typedef struct game_enemy_s game_enemy_t;
typedef struct maps_s maps_t;

void which_move(game_enemy_t *enemy, maps_t *maps, tab_enemies_t *tab);
void soldier_move(game_enemy_t *enemy, int move);
void tank_move(game_enemy_t *enemy, int move);
void map_position_move(game_enemy_t *enemy, int position);
#endif /* !MY_SOLDIER_DEPLACEMENTS_H_ */
