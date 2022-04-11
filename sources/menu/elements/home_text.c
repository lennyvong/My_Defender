/*
** EPITECH PROJECT, 2022
** my_defender
** File description:
** home_text
*/

#include <stdlib.h>
#include "my_structures.h"

void set_title(home_scene_t *home)
{
    char name[] = "My Defender";
    home->title = sfText_create();
    home->title_font = sfFont_createFromFile("assets/title_font.ttf");
    sfText_setPosition(home->title, (sfVector2f) {700, 50});
    sfText_setCharacterSize(home->title, 100);
    sfText_setString(home->title, name);
    sfText_setFont(home->title, home->title_font);
    sfText_setColor(home->title, sfBlack);
}

void set_text(home_scene_t *home, char *name, sfVector2f position, int i)
{
    home->text[i] = malloc(sizeof(text_t));
    home->text[i]->text = sfText_create();
    home->text[i]->font = sfFont_createFromFile("assets/title_font.ttf");
    sfText_setCharacterSize(home->text[i]->text, 60);
    sfText_setPosition(home->text[i]->text, position);
    sfText_setString(home->text[i]->text, name);
    sfText_setFont(home->text[i]->text, home->text[i]->font);
    sfText_setColor(home->text[i]->text, sfBlack);
}

void set_home_text(home_scene_t *home)
{
    set_text(home, "Play", (sfVector2f) {625, 375}, 0);
    set_text(home, "Options", (sfVector2f) {600, 550}, 1);
    set_text(home, "Ranking", (sfVector2f) {600, 725}, 2);
    set_text(home, "Help", (sfVector2f) {1100, 375}, 3);
    set_text(home, "Quit", (sfVector2f) {1100, 550}, 4);
    set_text(home, "Credits", (sfVector2f) {1100, 725}, 5);
}
