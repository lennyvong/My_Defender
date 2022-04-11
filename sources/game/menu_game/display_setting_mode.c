/*
** EPITECH PROJECT, 2022
** my_defender
** File description:
** display_setting_mode
*/

#include "my_structures.h"

void display_speaker(scenes_t *scenes, speaker_t *speaker);

void display_setting(scenes_t *scenes, manager_t *manager)
{
    sfRenderWindow_drawText(manager->window, scenes->pause->title, NULL);
    sfRenderWindow_drawSprite
    (manager->window, scenes->pause->elmt[1]->sprite, NULL);
    sfRenderWindow_drawSprite
    (manager->window, scenes->pause->elmt[2]->sprite, NULL);
    sfRenderWindow_drawSprite
    (manager->window, scenes->pause->elmt[3]->sprite, NULL);
    sfRenderWindow_drawSprite
    (manager->window, scenes->pause->elmt[4]->sprite, NULL);
}

void display_audio(scenes_t *scenes, manager_t *manager)
{
    sfRenderWindow_drawText(manager->window, scenes->pause->title, NULL);
    display_speaker(scenes, scenes->speaker);
}

void display_setting_mode(scenes_t *scenes, manager_t *manager)
{
    if (scenes->pause->setting == 0) {
        sfText_setString(scenes->pause->title, "Settings");
        display_setting(scenes, manager);
    } else if (scenes->pause->setting == 1) {
        sfText_setString(scenes->pause->title, "Sound");
        sfSprite_setPosition
        (scenes->speaker->sprite_speaker, (sfVector2f) {825, 450});
        display_audio(scenes, manager);
    }
}
