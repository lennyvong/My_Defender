/*
** EPITECH PROJECT, 2022
** my_archery.h
** File description:
** my_archery
*/

#ifndef MY_ARCHERY_H_
    #define MY_ARCHERY_H_
#include <SFML/Graphics.h>

typedef struct towers_elements_s towers_elements_t;
typedef struct scenes_s scenes_t;

void preset_tower(towers_elements_t *tower, int y,
int x, sfTexture *texture);
void my_towers(scenes_t *scenes, towers_elements_t *tower);
#endif /* !MY_ARCHERY_H_ */
