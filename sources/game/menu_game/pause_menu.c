/*
** EPITECH PROJECT, 2022
** B-MUL-200-PAR-2-1-mydefender-lenny.vongphouthone
** File description:
** pause_menu
*/

#include <stdlib.h>
#include "my_structures.h"
#include "game/my_pause.h"

void set_settings_text(game_pause_t *pause)
{
    pause->title = sfText_create();
    pause->title_font = sfFont_createFromFile("assets/cartoon.ttf");
    sfText_setCharacterSize(pause->title, 100);
    sfText_setPosition(pause->title, (sfVector2f) {775, 220});
    sfText_setString(pause->title, "Settings");
    sfText_setFont(pause->title, pause->title_font);
    sfText_setColor(pause->title, sfBlack);
}

void set_settings(game_pause_t *pause)
{
    set_settings_text(pause);
    set_setting_sprite(pause);
}

int menu_quit(scenes_t *scenes, manager_t *manager)
{
    while (sfRenderWindow_pollEvent(manager->window, &manager->event)) {
        if (event_pause_on(scenes, manager) == 1)
            return (1);
    }
}

void pause_menu(scenes_t *scenes, manager_t *manager)
{
    while (sfRenderWindow_isOpen(manager->window)) {
        sfRenderWindow_drawRectangleShape(manager->window, scenes->pause->back, NULL);
        if (menu_quit(scenes, manager) == 1)
            break;
        else {
            sfRenderWindow_drawSprite
            (manager->window, scenes->pause->elmt[0]->sprite, NULL);
            display_setting_mode(scenes, manager);
            sfRenderWindow_display(scenes->manager->window);
        }
    }
return;
}