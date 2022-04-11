/*
** EPITECH PROJECT, 2022
** home_menu.c
** File description:
** home_menu
*/

#include <stdlib.h>
#include <stdio.h>
#include "my_structures.h"
#include "home/my_home_buttons.h"
#include "home/my_home_book.h"
#include "home/my_home_level.h"
#include "home/my_home_display.h"
#include "home/my_home_text.h"

void play_game(scenes_t *scenes, int i_map);
void init_home_sprite(scenes_t *scenes);
void destroy_sound(scenes_t *scenes);
void set_home_sound(scenes_t *scenes);
void set_music(scenes_t *scenes);

void home_events(manager_t *manager, home_scene_t *home, scenes_t *scenes)
{
    sfVector2f click_pos;

    if (manager->event.type == sfEvtClosed)
        sfRenderWindow_close(manager->window);
    if (manager->event.type == sfEvtMouseButtonPressed) {
        click_pos.x = manager->event.mouseButton.x;
        click_pos.y = manager->event.mouseButton.y;
        for (int i = 0; i != home->nb_buttons; i++)
            button_is_clicked(home->buttons[i], scenes, click_pos, i);
    }
}

void preset_home_scene(home_scene_t *home, scenes_t *scenes)
{
    scenes->mode = -1;
    scenes->pause->setting = 0;
    home->fps = 1;
    home->nb_buttons = 6;
    home->sprite_home_back = sfSprite_create();
    scenes->book->clock_book = sfClock_create();
    scenes->smoke->clock_smoke = sfClock_create();
    init_home_sprite(scenes);
    set_music(scenes);
    home->home_back = sfTexture_createFromFile("assets/home_back.png", NULL);
    sfSprite_setScale(home->sprite_home_back, (sfVector2f) {1.5, 1.5});
    sfSprite_setTexture(home->sprite_home_back, home->home_back, sfFalse);
    set_home_button(home);
    set_home_text(home);
    set_home_sound(scenes);
    return;
}

static void case_mode(scenes_t *scenes)
{
    switch (scenes->mode) {
    case -1:
        display_home(scenes);
        break;
    case -2:
        set_level_text(scenes->home);
        display_level(scenes);
        break;
    case -3:
        scenes->home->buttons[1]->position = (sfVector2f) {625, 450};
        display_home_settings(scenes);
        break;
    case -4:
        set_help_text(scenes->home);
        display_help(scenes);
        break;
    case -6:
        display_credit(scenes);
        break;
    }
}

static void get_mode(scenes_t *scenes)
{
    case_mode(scenes);
    if (scenes->mode >= 0) {
        sfMusic_stop(scenes->music);
        sfMusic_play(scenes->game->music);
        sfMusic_setLoop(scenes->game->music, sfTrue);
        play_game(scenes, scenes->mode);
        return;
    }
}

void home_menu(scenes_t *scenes) {
    set_title(scenes->home);
    preset_home_scene(scenes->home, scenes);
    sfMusic_play(scenes->music);
    sfMusic_setLoop(scenes->music, sfTrue);
    while (sfRenderWindow_isOpen(scenes->manager->window)) {
        sfRenderWindow_display(scenes->manager->window);
        sfRenderWindow_clear(scenes->manager->window, sfBlack);
        sfRenderWindow_drawSprite
        (scenes->manager->window, scenes->home->sprite_home_back, NULL);
        if (scenes->mode == -10)
            break;
        get_mode(scenes);
        while (sfRenderWindow_pollEvent(scenes->manager->window,
        &scenes->manager->event))
            home_events(scenes->manager, scenes->home, scenes);
    }
    destroy_sound(scenes);
}
