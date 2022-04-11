/*
** EPITECH PROJECT, 2022
** my_generator_functions.h
** File description:
** my_generator_functions
*/

#ifndef MY_GENERATOR_FUNCTIONS_H_
    #define MY_GENERATOR_FUNCTIONS_H_

typedef struct game_enemy_s game_enemy_t;
typedef struct maps_s maps_t;

void identify_move(game_elements_t *base, game_enemy_t *enemy,
tab_enemies_t *tab, maps_t *maps);
void random_move(game_enemy_t *enemy, maps_t *maps, tab_enemies_t *tab,
int position);
#endif /* !MY_GENERATOR_FUNCTIONS_H_ */
