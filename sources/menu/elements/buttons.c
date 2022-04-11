/*
** EPITECH PROJECT, 2022
** buttons.C
** File description:
** buttons
*/

#include <stdlib.h>
#include "my_structures.h"
#include "home/my_home_text.h"
#include "home/my_home_display.h"

void play_game(scenes_t *scenes, int i_map);
void button_is_clicked
(button_t *button, scenes_t *scenes, sfVector2f click_position, int i);

void set_button_pos(home_scene_t *home)
{
    home->buttons[0]->position = (sfVector2f) {600, 360};
    home->buttons[1]->position = (sfVector2f) {600, 535};
    home->buttons[2]->position = (sfVector2f) {600, 710};
    home->buttons[3]->position = (sfVector2f) {1050, 360};
    home->buttons[4]->position = (sfVector2f) {1050, 535};
    home->buttons[5]->position = (sfVector2f) {1050, 710};
}

void set_home_button(home_scene_t *home)
{
    for (int i = 0; i != home->nb_buttons; i++) {
        home->buttons[i] = malloc(sizeof(button_t));
        home->buttons[i]->rect = sfRectangleShape_create();
    }
    set_button_pos(home);
    for (int i = 0; i != home->nb_buttons; i++) {
        home->buttons[i]->size = (sfVector2f) {200, 100};
        sfRectangleShape_setSize
        (home->buttons[i]->rect, home->buttons[i]->size);
        sfRectangleShape_setPosition
        (home->buttons[i]->rect, home->buttons[i]->position);
        sfRectangleShape_setFillColor
        (home->buttons[i]->rect, sfTransparent);
    }
    return;
}

void manage_button_rect
(sfVector2f position, home_scene_t *home, sfEvent event, int i)
{
    if ((event.mouseMove.x >= position.x
        && event.mouseMove.x <= position.x + 200)
        && (event.mouseMove.y >= position.y
        && event.mouseMove.y <= position.y + 100)) {
        sfText_setColor(home->text[i]->text, sfRed);
    } else
        sfText_setColor(home->text[i]->text, sfBlack);
}

void display_buttons(manager_t *manager, home_scene_t *home)
{
    for (int i = 0; i != home->nb_buttons; i++) {
        manage_button_rect
        (home->buttons[i]->position, home, manager->event, i);
        sfRenderWindow_drawText(manager->window, home->text[i]->text, NULL);
    }
}
