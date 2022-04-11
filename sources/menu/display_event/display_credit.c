/*
** EPITECH PROJECT, 2022
** B-MUL-200-PAR-2-1-mydefender-lenny.vongphouthone
** File description:
** display_credit
*/

#include "my_structures.h"

void display_book(scenes_t *scenes, float speed);
void set_text(home_scene_t *home, char *name, sfVector2f position, int i);
void set_home_text(home_scene_t *home);
void set_button_pos(home_scene_t *home);
void manage_button_rect
(sfVector2f position, home_scene_t *home, sfEvent event, int i);

void init_credit_text(home_scene_t *home)
{
    char *text = "This game is an Epitech project.\nIt is a tower defense"\
    "game programed\nin csfml.\nWe had 2 months to develop this game.\n";

    set_text(home, "Credits", (sfVector2f) {625, 325}, 0);
    set_text(home, "Creators", (sfVector2f) {1050, 325}, 1);
    set_text(home, text, (sfVector2f) {525, 420}, 2);
    set_text(home, "Lenny\nVongphouthone", (sfVector2f) {1000, 475}, 3);
    set_text(home, "Antony Jin", (sfVector2f) {1000, 630}, 4);
    set_text(home, "HOME", (sfVector2f) {1100, 725}, 5);
    sfText_setCharacterSize(home->text[2]->text, 25);
    sfText_setCharacterSize(home->text[3]->text, 50);
    sfText_setCharacterSize(home->text[4]->text, 50);
}

void display_credit_text(home_scene_t *home, manager_t *manager) {
    manage_button_rect(home->buttons[5]->position, home, manager->event, 5);
    for (int i = 0; i != home->nb_buttons; i++)
        sfRenderWindow_drawText(manager->window, home->text[i]->text, NULL);
}

void display_credit_event(scenes_t *scenes, int i)
{
    if (i == 5) {
        sfSound_play(scenes->smoke->smoke);
        scenes->smoke->rect_smoke.left = 0;
        sfSprite_setTextureRect
        (scenes->smoke->sprite_smoke, scenes->smoke->rect_smoke);
        set_home_text(scenes->home);
        set_button_pos(scenes->home);
        scenes->mode = -1;
    }
}

void display_credit(scenes_t *scenes)
{
    if (scenes->book->rect_book.left != 13500)
        display_book(scenes, 0.15);
    else {
        sfRenderWindow_drawSprite
        (scenes->manager->window, scenes->book->sprite_book, NULL);
        display_credit_text(scenes->home, scenes->manager);
    }
    sfRenderWindow_drawText
    (scenes->manager->window, scenes->home->title, NULL);
}
