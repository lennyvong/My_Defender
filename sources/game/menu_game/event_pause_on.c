/*
** EPITECH PROJECT, 2022
** my_defender
** File description:
** event_pause_on
*/

#include "my_structures.h"

void set_home_text(home_scene_t *home);
int manage_setting(scenes_t *scenes, manager_t *manager);
int manage_setting_audio(scenes_t *scenes, manager_t *manager);

static void case_three(scenes_t *scenes)
{
    scenes->mode = -1;
    sfSprite_setPosition
    (scenes->speaker->sprite_speaker, (sfVector2f) {625, 450});
    sfMusic_stop(scenes->game->music);
    sfMusic_play(scenes->music);
    sfMusic_setLoop(scenes->music, sfTrue);
    set_home_text(scenes->home);
}

int check_setting_click(scenes_t *scenes, manager_t *manager,
sfVector2f pos, int i)
{
    if (i == 1) {
        scenes->mode = -10;
        return (1);
    }
    if (i == 2) {
        return (1);
    }
    if (i == 3) {
        case_three(scenes);
        return (1);
    }
    if (i == 4) {
        scenes->pause->setting = 1;
        return (0);
    }
    return (0);
}

void manage_hover_rect(scenes_t *scenes, sfVector2f pos, sfEvent event, int i)
{
    if ((event.mouseMove.x >= pos.x
        && event.mouseMove.x <= pos.x + 300)
        && (event.mouseMove.y >= pos.y
        && event.mouseMove.y <= pos.y + 100))
        scenes->pause->elmt[i]->rect.left = 550;
    else
        scenes->pause->elmt[i]->rect.left = 0;
    sfSprite_setTextureRect
    (scenes->pause->elmt[i]->sprite, scenes->pause->elmt[i]->rect);
}

int event_pause_on(scenes_t *scenes, manager_t *manager)
{
    if (scenes->pause->setting == 0)
        return (manage_setting(scenes, manager));
    if (scenes->pause->setting == 1)
        return (manage_setting_audio(scenes, manager));
    return (0);
}
