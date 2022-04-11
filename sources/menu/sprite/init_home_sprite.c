/*
** EPITECH PROJECT, 2022
** B-MUL-200-PAR-2-1-mydefender-lenny.vongphouthone
** File description:
** init_home_sprite
*/

#include "my_structures.h"

void init_book(book_t *book);
void init_smoke(smoke_t *smoke);
void init_speaker(speaker_t *speaker);

void init_home_sprite(scenes_t *scenes)
{
    init_book(scenes->book);
    init_smoke(scenes->smoke);
    init_speaker(scenes->speaker);
}
