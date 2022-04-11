/*
** EPITECH PROJECT, 2022
** open_window.c
** File description:
** open_window
*/

#include "my_structures.h"
#include <stdlib.h>

void set_window(manager_t *manager) {
    sfVideoMode video_mode = {1920, 1080, 64};
    manager->window =
    sfRenderWindow_create(video_mode, "my_defender", sfDefaultStyle, NULL);
    sfRenderWindow_setFramerateLimit(manager->window, 60);
    return;
}
