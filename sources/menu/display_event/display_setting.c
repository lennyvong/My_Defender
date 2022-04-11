/*
** EPITECH PROJECT, 2022
** B-MUL-200-PAR-2-1-mydefender-lenny.vongphouthone
** File description:
** display_setting
*/

#include "my_structures.h"
#include "home/my_home_display.h"
#include "home/my_home_text.h"

void manage_button_rect
(sfVector2f position, home_scene_t *home, sfEvent event, int i);
void set_button_pos(home_scene_t *home);
void set_home(scenes_t *scenes);

void init_setting_text(home_scene_t *home)
{
    set_text(home, "Sound", (sfVector2f) {625, 325}, 0);
    set_text(home, "Framerate", (sfVector2f) {1050, 325}, 1);
    set_text(home, "30 fps", (sfVector2f) {1075, 400}, 2);
    set_text(home, "60 fps", (sfVector2f) {1075, 500}, 3);
    set_text(home, "120 fps", (sfVector2f) {1075, 600}, 4);
    set_text(home, "HOME", (sfVector2f) {1100, 725}, 5);
}

void display_setting_text(home_scene_t *home, manager_t *manager) {
    manage_button_rect((sfVector2f) {600, 460}, home, manager->event, 0);
    manage_button_rect((sfVector2f) {1055, 410}, home, manager->event, 2);
    manage_button_rect((sfVector2f) {1055, 510}, home, manager->event, 3);
    manage_button_rect((sfVector2f) {1055, 610}, home, manager->event, 4);
    manage_button_rect(home->buttons[5]->position, home, manager->event, 5);
    if (home->fps == 0)
        sfText_setColor(home->text[2]->text, (sfColor){255, 0, 128, 255});
    else if (home->fps == 1)
        sfText_setColor(home->text[3]->text, (sfColor){255, 0, 128, 255});
    else
        sfText_setColor(home->text[4]->text, (sfColor){255, 0, 128, 255});
    for (int i = 0; i != home->nb_buttons; i++)
        sfRenderWindow_drawText(manager->window, home->text[i]->text, NULL);
}

static void event_case(scenes_t *scenes, int i)
{
    switch (i) {
        case 2:
        sfRenderWindow_setFramerateLimit(scenes->manager->window, 30);
        scenes->home->fps = 0;
        break;
        case 3:
        scenes->home->fps = 1;
        sfRenderWindow_setFramerateLimit(scenes->manager->window, 60);
        break;
        case 4:
        scenes->home->fps = 2;
        sfRenderWindow_setFramerateLimit(scenes->manager->window, 120);
        break;
        case 5:
        set_home(scenes);
        set_button_pos(scenes->home);
        break;
    }
}

void display_setting_event(scenes_t *scenes, int i)
{
    event_case(scenes, i);
    if (i == 1 && scenes->speaker->sound == 0)
        scenes->speaker->sound = 1;
    else if (i == 1 && scenes->speaker->sound == 1)
        scenes->speaker->sound = 0;
}

void display_home_settings(scenes_t *scenes)
{
    if (scenes->book->rect_book.left != 13500)
        display_book(scenes, 0.15);
    else {
        sfRenderWindow_drawSprite
        (scenes->manager->window, scenes->book->sprite_book, NULL);
        display_setting_text(scenes->home, scenes->manager);
        display_speaker(scenes, scenes->speaker);
    }
    sfRenderWindow_drawText
    (scenes->manager->window, scenes->home->title, NULL);
}
