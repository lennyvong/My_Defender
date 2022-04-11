/*
** EPITECH PROJECT, 2022
** end_game.c
** File description:
** end_game
*/

#include <stdlib.h>
#include "my_structures.h"

void set_home_text(home_scene_t *home);
void play_game(scenes_t *scenes, int i_map);

static int check_setting_click(scenes_t *scenes, manager_t *manager,
sfVector2f pos, int i)
{
    if (i == 1) {
        scenes->mode = -1;
        sfSprite_setPosition
        (scenes->speaker->sprite_speaker, (sfVector2f) {625, 450});
        sfMusic_stop(scenes->game->music);
        sfMusic_play(scenes->music);
        sfMusic_setLoop(scenes->music, sfTrue);
        set_home_text(scenes->home);
        scenes->endscene = 0;
    }
    if (i == 2) {
        play_game(scenes, scenes->mode);
        scenes->endscene = 0;
    }
    if (i == 3) {
        scenes->mode = -10;
        scenes->endscene = 0;
    }
}

static void manage_hover(scenes_t *scenes, sfVector2f pos, sfEvent event,
int i)
{
    if ((event.mouseMove.x >= pos.x
        && event.mouseMove.x <= pos.x + 300)
        && (event.mouseMove.y >= pos.y
        && event.mouseMove.y <= pos.y + 100))
        scenes->end->elmt[i]->rect.left = 550;
    else
        scenes->end->elmt[i]->rect.left = 0;
    sfSprite_setTextureRect
    (scenes->end->elmt[i]->sprite, scenes->end->elmt[i]->rect);
}

static void manage_setting(scenes_t *scenes, manager_t *manager)
{
    for (int i = 1; i != 5; i++) {
        manage_hover(scenes, scenes->end->elmt[i]->pos, manager->event, i);
        if (scenes->manager->event.type == sfEvtMouseButtonPressed
        &&(scenes->manager->event.mouseButton.x >= scenes->end->elmt[i]->pos.x
        && scenes->manager->event.mouseButton.x
        <= scenes->end->elmt[i]->pos.x + 300)
        && (scenes->manager->event.mouseButton.y >= scenes->end->elmt[i]->pos.y
        && scenes->manager->event.mouseButton.y
        <= scenes->end->elmt[i]->pos.y + 100)) {
            check_setting_click
            (scenes, scenes->manager, scenes->end->elmt[i]->pos, i);
        }
    }
    if (manager->event.type == sfEvtClosed)
        sfRenderWindow_close(manager->window);
}

int end_game(scenes_t *scenes, manager_t *manager)
{
    while (sfRenderWindow_isOpen(scenes->manager->window)
        && scenes->endscene == 1) {
        manage_setting(scenes, manager);
        sfRenderWindow_drawRectangleShape
        (scenes->manager->window, scenes->pause->back, NULL);
        sfRenderWindow_drawSprite
        (manager->window, scenes->end->elmt[0]->sprite, NULL);
        sfRenderWindow_drawSprite
        (manager->window, scenes->end->elmt[1]->sprite, NULL);
        sfRenderWindow_drawSprite
        (manager->window, scenes->end->elmt[2]->sprite, NULL);
        sfRenderWindow_drawSprite
        (manager->window, scenes->end->elmt[3]->sprite, NULL);
        sfRenderWindow_drawSprite
        (manager->window, scenes->end->elmt[4]->sprite, NULL);
        sfRenderWindow_display(scenes->manager->window);
        while (sfRenderWindow_pollEvent(manager->window, &manager->event))
            manage_setting(scenes, manager);
    }
    return (0);
}

void static set_button(end_game_t *end)
{
    end->elmt[0]->texture =
    sfTexture_createFromFile("assets/DxL.png", NULL);
    end->elmt[1]->texture =
    sfTexture_createFromFile("assets/home.png", NULL);
    end->elmt[2]->texture =
    sfTexture_createFromFile("assets/restart.png", NULL);
    end->elmt[3]->texture =
    sfTexture_createFromFile("assets/quit.png", NULL);
    end->elmt[4]->texture =
    sfTexture_createFromFile("assets/ranking.png", NULL);
    for (int i = 0; i != 5; i++) {
        end->elmt[i]->sprite = sfSprite_create();
        sfSprite_setTexture
        (end->elmt[i]->sprite, end->elmt[i]->texture, sfFalse);
        sfSprite_setTextureRect
        (end->elmt[i]->sprite, end->elmt[i]->rect);
    }
    end->elmt[0]->pos = (sfVector2f) {100, 600};
    end->elmt[1]->pos = (sfVector2f) {600, 730};
    end->elmt[2]->pos = (sfVector2f) {200, 730};
    end->elmt[3]->pos = (sfVector2f) {1000, 730};
    end->elmt[4]->pos = (sfVector2f) {1400, 730};
    sfSprite_setPosition(end->elmt[0]->sprite, (sfVector2f) {670, 30});
    sfSprite_setPosition(end->elmt[1]->sprite, (sfVector2f) {480, 730});
    sfSprite_setPosition(end->elmt[2]->sprite, (sfVector2f) {60, 730});
    sfSprite_setPosition(end->elmt[3]->sprite, (sfVector2f) {880, 730});
    sfSprite_setPosition(end->elmt[4]->sprite, (sfVector2f) {1300, 730});
}

void set_lose(end_game_t *end)
{
     for (int i = 0; i != 5; i++) {
        end->elmt[i] = malloc(sizeof(element_t));
        if (i == 0) {
            end->elmt[i]->rect.top = 0;
            end->elmt[i]->rect.left = 1300;
            end->elmt[i]->rect.width = 1300;
            end->elmt[i]->rect.height = 557;
        }
        if (i >= 1) {
            end->elmt[i]->rect.top = 0;
            end->elmt[i]->rect.left = 0;
            end->elmt[i]->rect.width = 500;
            end->elmt[i]->rect.height = 150;
        }
     }
    set_button(end);
}

int check_end_game(scenes_t *scenes)
{
    if (scenes->game->decor->base->life < 900) {
        scenes->endscene = 1;
        set_lose(scenes->end);
        end_game(scenes, scenes->manager);
    }
}
