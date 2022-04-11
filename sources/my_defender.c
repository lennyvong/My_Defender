/*
** EPITECH PROJECT, 2022
** my_defender.c
** File description:
** my_defender
*/

#include <stdlib.h>
#include "my_structures.h"
#include "home/my_menu.h"
#include "my_macro.h"

void set_window(manager_t *manager);

void malloc_scene(scenes_t *scenes) {
    scenes->home = malloc(sizeof(home_scene_t));
    scenes->manager = malloc(sizeof(manager_t));
    scenes->game = malloc(sizeof(game_scene_t));
    scenes->pause = malloc(sizeof(game_pause_t));
    scenes->book = malloc(sizeof(book_t));
    scenes->smoke = malloc(sizeof(smoke_t));
    scenes->speaker = malloc(sizeof(speaker_t));
    scenes->end = malloc(sizeof(end_game_t));
    return;
}

void my_defender(void) {
    scenes_t scenes;
    malloc_scene(&scenes);
    set_window(scenes.manager);
    home_menu(&scenes);
    return;
}
