/*
** EPITECH PROJECT, 2022
** my_defender
** File description:
** button_is_clicked
*/

#include "my_structures.h"
#include "home/my_home_display.h"

static void case_button(scenes_t *scenes, int i)
{
    switch (scenes->mode) {
        case -1:
        sfSound_play(scenes->book->page);
        display_home_event1(scenes, i);
        break;
        case -2:
        display_level_event(scenes, i);
        break;
        case -3:
        display_setting_event(scenes, i);
        break;
        case -4:
        display_help_event(scenes, i);
        break;
        case -6:
        display_credit_event(scenes, i);
        break;
    }
}

void button_is_clicked
(button_t *button, scenes_t *scenes, sfVector2f click_position, int i)
{
    if ((click_position.x >= button->position.x
    && click_position.x <= button->position.x + 200)
    && (click_position.y >= button->position.y
    && click_position.y <= button->position.y + 100)) {
        case_button(scenes, i);
    }
}