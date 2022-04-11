/*
** EPITECH PROJECT, 2022
** B-MUL-200-PAR-2-1-mydefender-lenny.vongphouthone
** File description:
** manage_sound
*/

#include "my_structures.h"

void destroy_sound(scenes_t *scenes)
{
    sfSoundBuffer_destroy(scenes->book->page_sound);
    sfSound_destroy(scenes->book->page);
    sfSoundBuffer_destroy(scenes->smoke->smoke_sound);
    sfSound_destroy(scenes->smoke->smoke);
    sfSound_destroy(scenes->game->coin);
    sfMusic_destroy(scenes->music);
}

void unmute_all(scenes_t *scenes)
{
    sfSound_setVolume(scenes->book->page, 100);
    sfSound_setVolume(scenes->smoke->smoke, 100);
    sfSound_setVolume(scenes->game->coin, 100);
    sfMusic_setVolume(scenes->music, 50);
    sfMusic_setVolume(scenes->game->music, 50);
}

void mute_all(scenes_t *scenes)
{
    sfSound_setVolume(scenes->book->page, 0);
    sfSound_setVolume(scenes->smoke->smoke, 0);
    sfSound_setVolume(scenes->game->coin, 0);
    sfMusic_setVolume(scenes->music, 0);
    sfMusic_setVolume(scenes->game->music, 0);
}

void manage_sound(scenes_t *scenes)
{
    if (scenes->speaker->sound == 0) {
        mute_all(scenes);
        scenes->speaker->sound = 1;
    } else {
        unmute_all(scenes);
        scenes->speaker->sound = 0;
    }
}
