/*
** EPITECH PROJECT, 2022
** my_defender
** File description:
** my_music
*/

#include "my_structures.h"

void set_music(scenes_t *scenes)
{
    scenes->music = sfMusic_createFromFile("assets/home_music.ogg");
    sfMusic_setVolume(scenes->music, 50);
    scenes->game->music = sfMusic_createFromFile("assets/game_music.ogg");
    sfMusic_setVolume(scenes->game->music, 50);
}
