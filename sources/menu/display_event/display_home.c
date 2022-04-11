/*
** EPITECH PROJECT, 2022
** B-MUL-200-PAR-2-1-mydefender-lenny.vongphouthone
** File description:
** display_home
*/

#include <stdio.h>
#include "my_structures.h"
#include "home/my_home_display.h"
#include "home/my_home_text.h"

void display_home_event2(scenes_t *scenes, int i)
{
    if (i == 2);
    if (i == 3) {
        scenes->book->rect_book.left = 7500;
        sfSprite_setTextureRect
        (scenes->book->sprite_book, scenes->book->rect_book);
        scenes->mode = -4;
    }
    if (i == 4)
        scenes->mode = -10;
    if (i == 5) {
        scenes->book->rect_book.left = 7500;
        init_credit_text(scenes->home);
        scenes->mode = -6;
    }
}

void display_home_event1(scenes_t *scenes, int i)
{
    if (i == 0) {
        scenes->book->rect_book.left = 7500;
        sfSprite_setTextureRect
        (scenes->book->sprite_book, scenes->book->rect_book);
        scenes->mode = -2;
    }
    if (i == 1) {
        scenes->book->rect_book.left = 7500;
        init_setting_text(scenes->home);
        sfSprite_setTextureRect
        (scenes->book->sprite_book, scenes->book->rect_book);
        scenes->home->buttons[2]->position = (sfVector2f) {1050, 410};
        scenes->home->buttons[3]->position = (sfVector2f) {1050, 510};
        scenes->home->buttons[4]->position = (sfVector2f) {1050, 610};
        scenes->mode = -3;
    }
    display_home_event2(scenes, i);
}

void display_text(manager_t *manager, home_scene_t *home)
{
    for (int i = 0; i != home->nb_buttons; i++)
        sfRenderWindow_drawText(manager->window, home->text[i]->text, NULL);
}

void display_home(scenes_t *scenes)
{
    if (scenes->book->rect_book.left != 13500) {
        display_book(scenes, 0.1);
        sfSound_play(scenes->smoke->smoke);
    } else if (scenes->smoke->rect_smoke.left != 4800) {
        sfRenderWindow_drawSprite
        (scenes->manager->window, scenes->book->sprite_book, NULL);
        display_text(scenes->manager, scenes->home);
        display_smoke(scenes);
    } else {
        sfRenderWindow_drawSprite
        (scenes->manager->window, scenes->book->sprite_book, NULL);
        display_buttons(scenes->manager, scenes->home);
        display_text(scenes->manager, scenes->home);
    }
    sfRenderWindow_drawText
    (scenes->manager->window, scenes->home->title, NULL);
}
