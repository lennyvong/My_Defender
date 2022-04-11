/*
** EPITECH PROJECT, 2022
** my_defender
** File description:
** init_sound
*/

#include "my_structures.h"

void set_home_sound(scenes_t *scenes)
{
    scenes->book->allpage = sfSound_create();
    scenes->book->allpage_sound =
    sfSoundBuffer_createFromFile("assets/allpage.ogg");
    sfSound_setBuffer(scenes->book->allpage, scenes->book->allpage_sound);
    scenes->book->page = sfSound_create();
    scenes->book->page_sound = sfSoundBuffer_createFromFile("assets/page.ogg");
    sfSound_setBuffer(scenes->book->page, scenes->book->page_sound);
    scenes->smoke->smoke = sfSound_create();
    scenes->smoke->smoke_sound =
    sfSoundBuffer_createFromFile("assets/smoke.ogg");
    sfSound_setBuffer(scenes->smoke->smoke, scenes->smoke->smoke_sound);
    sfSound_play(scenes->book->allpage);
    scenes->game->coin = sfSound_create();
    scenes->game->coin_sound = sfSoundBuffer_createFromFile("assets/coin.ogg");
    sfSound_setBuffer(scenes->game->coin, scenes->game->coin_sound);
    sfSound_play(scenes->book->allpage);
}
