/*
** EPITECH PROJECT, 2022
** B-MUL-200-PAR-2-1-mydefender-lenny.vongphouthone
** File description:
** display_level
*/

#include "my_structures.h"
#include "home/my_home_text.h"

void display_book(scenes_t *scenes, float speed);
void manage_button_rect(sfVector2f position, home_scene_t *home, sfEvent event,
int i);

void set_level_text(home_scene_t *home)
{
    set_text(home, "Map 1", (sfVector2f) {625, 375}, 0);
    set_text(home, "Map 2", (sfVector2f) {625, 550}, 1);
    set_text(home, "Map 3", (sfVector2f) {625, 725}, 2);
    set_text(home, "Map 4", (sfVector2f) {1100, 375}, 3);
    set_text(home, "Map 5", (sfVector2f) {1100, 550}, 4);
    set_text(home, "HOME", (sfVector2f) {1100, 725}, 5);
}

void set_home(scenes_t *scenes)
{
    sfSound_play(scenes->smoke->smoke);
    scenes->smoke->rect_smoke.left = 0;
    sfSprite_setTextureRect
    (scenes->smoke->sprite_smoke, scenes->smoke->rect_smoke);
    set_home_text(scenes->home);
    scenes->mode = -1;
}

void display_level_event(scenes_t *scenes, int i)
{
    switch (i) {
        case 0:
        scenes->mode = 0;;
        break;
        case 1:
        scenes->mode = 1;
        break;
        case 2:
        scenes->mode = 2;
        break;
        case 3:
        scenes->mode = 3;
        break;
        case 4:
        scenes->mode = 4;
        break;
        case 5:
        set_home(scenes);
        break;
    }
}

void display_text_level(manager_t *manager, home_scene_t *home)
{
    for (int i = 0; i != home->nb_buttons; i++) {
        manage_button_rect
        (home->buttons[i]->position, home, manager->event, i);
        sfRenderWindow_drawText(manager->window, home->text[i]->text, NULL);
    }
}

void display_level(scenes_t *scenes)
{
    if (scenes->book->rect_book.left != 13500)
        display_book(scenes, 0.15);
    else {
        sfRenderWindow_drawSprite
        (scenes->manager->window, scenes->book->sprite_book, NULL);
        display_text_level(scenes->manager, scenes->home);
    }
    sfRenderWindow_drawText(scenes->manager->window, scenes->home->title,
    NULL);
}
