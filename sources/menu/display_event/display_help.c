/*
** EPITECH PROJECT, 2022
** my_defender
** File description:
** display_help
*/

#include "my_structures.h"
#include "home/my_home_display.h"
#include "home/my_home_text.h"

void manage_button_rect
(sfVector2f position, home_scene_t *home, sfEvent event, int i);
void set_button_pos(home_scene_t *home);

void set_help_text(home_scene_t *home)
{
    char *text = "You own the last castle in the world\neverything evolved, "\
    "people now have\nguns, tanks or other stuff like this\n"\
    "because they think "\
    "that it is stronger.\n\nBut it is false !\n"\
    "Prove them wrong !\n\n\n\t\tDefend your castle !\n";

    char *help = "You start with 20 gold.\nKill soldier and tanks to earn"\
    "\nmore money.\n\nThen, you could place tower\non the grass to kill "\
    "enemies\nand uprgade or buy new towers.\nYou can press the escape key\n"\
    "to get into the settings\n";

    set_text(home, "History", (sfVector2f) {625, 335}, 0);
    set_text(home, text, (sfVector2f) {525, 450}, 1);
    set_text(home, "How to play", (sfVector2f) {1000, 335}, 2);
    set_text(home, "HOME", (sfVector2f) {1100, 725}, 3);
    set_text(home, help, (sfVector2f) {1000, 450}, 4);
    sfText_setCharacterSize(home->text[1]->text, 25);
    sfText_setCharacterSize(home->text[4]->text, 25);
}

void display_help_text(home_scene_t *home, manager_t *manager) {
    manage_button_rect((sfVector2f) {1100, 725}, home, manager->event, 3);
    for (int i = 0; i != 5; i++)
        sfRenderWindow_drawText(manager->window, home->text[i]->text, NULL);
}

void display_help_event(scenes_t *scenes, int i)
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

void display_help(scenes_t *scenes)
{
    if (scenes->book->rect_book.left != 13500)
        display_book(scenes, 0.15);
    else {
        sfRenderWindow_drawSprite
        (scenes->manager->window, scenes->book->sprite_book, NULL);
        display_help_text(scenes->home, scenes->manager);
    }
    sfRenderWindow_drawText
    (scenes->manager->window, scenes->home->title, NULL);
}