/*
** EPITECH PROJECT, 2022
** my_defender
** File description:
** manage_setting
*/

#include "my_structures.h"

void manage_hover_rect(scenes_t *scenes, sfVector2f pos, sfEvent event, int i);
void manage_sound(scenes_t *scenes);
int check_setting_click(scenes_t *scenes, manager_t *manager,
sfVector2f pos, int i);

int manage_setting(scenes_t *scenes, manager_t *manager)
{
    for (int i = 1; i != 5; i++) {
        manage_hover_rect(scenes, scenes->pause->elmt[i]->pos, manager->event, i);
        if (scenes->manager->event.type == sfEvtMouseButtonPressed
            && scenes->manager->event.mouseButton.x
            >= scenes->pause->elmt[i]->pos.x
            && scenes->manager->event.mouseButton.x
            <= scenes->pause->elmt[i]->pos.x + 300
            && scenes->manager->event.mouseButton.y
            >= scenes->pause->elmt[i]->pos.y
            && scenes->manager->event.mouseButton.y
            <= scenes->pause->elmt[i]->pos.y + 100) {
                return (check_setting_click(scenes, scenes->manager,
                scenes->pause->elmt[i]->pos, i));
        }
    }
    if (manager->event.type == sfEvtClosed)
        sfRenderWindow_close(manager->window);
}

int manage_setting_audio(scenes_t *scenes, manager_t *manager)
{
    if (manager->event.type == sfEvtKeyPressed &&
        manager->event.key.code == sfKeyEscape) {
        scenes->pause->setting = 0;
        return (0);
    }
    if (manager->event.type == sfEvtMouseButtonPressed
    && manager->event.mouseButton.x >= 820
    && manager->event.mouseButton.x <= 960
    && manager->event.mouseButton.y >= 450
    && manager->event.mouseButton.y <= 560) {
        manage_sound(scenes);
        return (0);
    }
    if (manager->event.type == sfEvtClosed)
        sfRenderWindow_close(manager->window);
}
