/*
** EPITECH PROJECT, 2022
** B-MUL-200-PAR-2-1-mydefender-lenny.vongphouthone
** File description:
** speaker
*/

#include "my_structures.h"

void mute_all(scenes_t *scenes);
void unmute_all(scenes_t *scenes);

void init_bar(speaker_t *speaker)
{
    speaker->texture_bar = sfTexture_createFromFile("assets/bar.png", NULL);
    speaker->sprite_bar = sfSprite_create();
    speaker->texture_bar2 = sfTexture_createFromFile("assets/bar2.png", NULL);
    speaker->sprite_bar2 = sfSprite_create();
    speaker->pos_bar = (sfVector2f) {696, 707};
    sfSprite_setScale(speaker->sprite_bar2, (sfVector2f) {2, 2});
    sfSprite_setPosition(speaker->sprite_bar, (sfVector2f) {550, 620});
    sfSprite_setPosition(speaker->sprite_bar2, (sfVector2f) {300, 455});
    sfSprite_setTexture(speaker->sprite_bar, speaker->texture_bar, sfFalse);
    sfSprite_setTexture(speaker->sprite_bar2, speaker->texture_bar2, sfFalse);
}

void init_speaker(speaker_t *speaker)
{
    speaker->sound = 0;
    speaker->texture_speaker =
    sfTexture_createFromFile("assets/speaker.png", NULL);
    speaker->sprite_speaker = sfSprite_create();
    speaker->rect_speaker.top = 0;
    speaker->rect_speaker.left = 0;
    speaker->rect_speaker.width = 500;
    speaker->rect_speaker.height = 500;
    init_bar(speaker);
    sfSprite_setTexture
    (speaker->sprite_speaker, speaker->texture_speaker, sfFalse);
    sfSprite_setPosition(speaker->sprite_speaker, (sfVector2f) {625, 450});
    sfSprite_setScale(speaker->sprite_speaker, (sfVector2f) {0.25, 0.25});
    sfSprite_setTextureRect(speaker->sprite_speaker, speaker->rect_speaker);
}

static void set_speaker(scenes_t *scenes, speaker_t *speaker)
{
    sfSprite_setTextureRect(speaker->sprite_speaker, speaker->rect_speaker);
    sfRenderWindow_drawSprite
    (scenes->manager->window, scenes->speaker->sprite_speaker, NULL);
    sfRenderWindow_drawSprite
    (scenes->manager->window, scenes->speaker->sprite_bar, NULL);
    sfRenderWindow_drawSprite
    (scenes->manager->window, scenes->speaker->sprite_bar2, NULL);
}

void display_speaker(scenes_t *scenes, speaker_t *speaker)
{
    if (speaker->sound == 0) {
        speaker->rect_speaker.left = 0;
        set_speaker(scenes, speaker);
        unmute_all(scenes);
    } else if (speaker->sound == 1) {
        speaker->rect_speaker.left = 500;
        set_speaker(scenes, speaker);
        mute_all(scenes);
    }
}
