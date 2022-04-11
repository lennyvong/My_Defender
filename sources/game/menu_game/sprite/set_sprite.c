/*
** EPITECH PROJECT, 2022
** my_defender
** File description:
** set_sprite
*/

#include <stdlib.h>
#include "my_structures.h"

static void set_setting_elmt(game_pause_t *pause)
{
    pause->back = sfRectangleShape_create();
    sfRectangleShape_setSize(pause->back, (sfVector2f) {1920, 1080});
    sfRectangleShape_setFillColor(pause->back, (sfColor) {0, 0, 0, 2});
    pause->elmt[0]->texture =
    sfTexture_createFromFile("assets/bord.png", NULL);
    pause->elmt[1]->texture =
    sfTexture_createFromFile("assets/quit.png", NULL);
    pause->elmt[2]->texture =
    sfTexture_createFromFile("assets/resume.png", NULL);
    pause->elmt[3]->texture =
    sfTexture_createFromFile("assets/home.png", NULL);
    pause->elmt[4]->texture =
    sfTexture_createFromFile("assets/sound.png", NULL);
}

static void set_setting_elmt_pos(game_pause_t *pause)
{
    pause->elmt[1]->pos = (sfVector2f) {625, 530};
    pause->elmt[2]->pos = (sfVector2f) {810, 675};
    pause->elmt[3]->pos = (sfVector2f) {630, 390};
    pause->elmt[4]->pos = (sfVector2f) {970, 390};
    sfSprite_setPosition(pause->elmt[0]->sprite, (sfVector2f) {-270, -500});
    sfSprite_setPosition(pause->elmt[1]->sprite, (sfVector2f) {500, 500});
    sfSprite_setPosition(pause->elmt[2]->sprite, (sfVector2f) {680, 650});
    sfSprite_setPosition(pause->elmt[3]->sprite, (sfVector2f) {497, 360});
    sfSprite_setPosition(pause->elmt[4]->sprite, (sfVector2f) {840, 360});
    sfSprite_setScale(pause->elmt[0]->sprite, (sfVector2f) {3, 3});
}

void set_setting_sprite(game_pause_t *pause)
{
    for (int i = 0; i != 5; i++) {
        pause->elmt[i] = malloc(sizeof(element_t));
        if (i >= 1) {
            pause->elmt[i]->rect.top = 0;
            pause->elmt[i]->rect.left = 0;
            pause->elmt[i]->rect.width = 500;
            pause->elmt[i]->rect.height = 150;
        }
    }
    set_setting_elmt(pause);
    for (int i = 0; i != 5; i++) {
        pause->elmt[i]->sprite = sfSprite_create();
        sfSprite_setTexture
        (pause->elmt[i]->sprite, pause->elmt[i]->texture, sfFalse);
        if (i >= 1)
            sfSprite_setTextureRect
            (pause->elmt[i]->sprite, pause->elmt[i]->rect);
    }
    set_setting_elmt_pos(pause);
}
