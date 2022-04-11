/*
** EPITECH PROJECT, 2022
** my_defender
** File description:
** set_inventory
*/

#include <stdlib.h>
#include "my_structures.h"

static void set_rectangle(game_scene_t *game)
{
    sfRectangleShape_setSize(game->shop[6]->rect, (sfVector2f) {80, 124});
    sfRectangleShape_setFillColor(game->shop[6]->rect, sfTransparent);
    sfRectangleShape_setSize(game->shop[0]->rect, (sfVector2f) {800, 533});
    sfRectangleShape_setPosition(game->shop[0]->rect,
    (sfVector2f) {1870, 150});
    game->shop[0]->texture = sfTexture_createFromFile("assets/shop.png", NULL);
    game->shop[1]->texture =
    sfTexture_createFromFile("assets/archer.png", NULL);
    game->shop[2]->texture =
    sfTexture_createFromFile("assets/wizard1.png", NULL);
    game->shop[3]->texture =
    sfTexture_createFromFile("assets/wizard2.png", NULL);
    game->shop[4]->texture =
    sfTexture_createFromFile("assets/wizard3.png", NULL);
    for (int i = 0; i != 5; i++)
        sfRectangleShape_setTexture
        (game->shop[i]->rect, game->shop[i]->texture, sfFalse);
}

static void set_text_str(game_scene_t *game)
{
    game->shop[1]->string = "5";
    game->shop[2]->string = "10";
    game->shop[3]->string = "20";
    game->shop[4]->string = "50";
    game->shop[5]->string = "0";
    game->shop[6]->string = "0";
    sfText_setString(game->shop[1]->price, "5");
    sfText_setString(game->shop[2]->price, "10");
    sfText_setString(game->shop[3]->price, "20");
    sfText_setString(game->shop[4]->price, "50");
    sfText_setString(game->shop[5]->price, "0");
    sfText_setString(game->shop[6]->price, "0");
}

static void set_text_shop(game_scene_t *game)
{
    int a = 0;

    for (int i = 0; i != 7; i++) {
        game->shop[i]->price = sfText_create();
        if (i != 0)
            sfText_setPosition
            (game->shop[i]->price, (sfVector2f) {612 + a, 1080});
        game->shop[i]->font = sfFont_createFromFile("assets/cartoon.ttf");
        sfText_setColor(game->shop[i]->price, sfYellow);
        sfText_setFont(game->shop[i]->price, game->shop[i]->font);
        sfText_setCharacterSize(game->shop[i]->price, 20);
    }
    set_text_str(game);
}

static void set_shop(scenes_t *scenes, game_scene_t *game)
{
    sfRectangleShape_setPosition(game->inventory[0]->rect,
    (sfVector2f) {570, 950});
    game->inventory[0]->texture =
    sfTexture_createFromFile("assets/inv.png", NULL);
    sfRectangleShape_setTexture
    (game->inventory[0]->rect, game->inventory[0]->texture, sfFalse);
    game->shopping = 0;
    for (int i = 0; i < 7; i++) {
        game->shop[i] = malloc(sizeof(shop_t));
        game->shop[i]->rect = sfRectangleShape_create();
        if (i != 0)
            sfRectangleShape_setSize(game->shop[i]->rect,
            (sfVector2f) {56, 100});
        if (i >= 1 && i < 7)
            sfRectangleShape_setPosition(game->shop[i]->rect,
            (sfVector2f) {1970, 170});
        game->shop[i]->id = i;
    }
    set_rectangle(game);
    set_text_shop(game);
}

void set_inventory(scenes_t *scenes, game_scene_t *game)
{
    int a = 0;
    game->mode = 0;
    scenes->manager->mouse.inv_idx = -1;
    scenes->manager->mouse.id = 0;

    for (int i = 0; i < 9; i++) {
        game->inventory[i] = malloc(sizeof(inventory_t));
        game->inventory[i]->rect = sfRectangleShape_create();
        if (i != 0) {
            sfRectangleShape_setSize
            (game->inventory[i]->rect, (sfVector2f) {75, 75});
            sfRectangleShape_setPosition
            (game->inventory[i]->rect, (sfVector2f) {612 + a, 1080});
            sfRectangleShape_setFillColor
            (game->inventory[i]->rect, sfTransparent);
            a += 83;
            game->inventory[i]->id = 0;
        }
    }
    sfRectangleShape_setSize(game->inventory[0]->rect,
    (sfVector2f) {750, 750});
    set_shop(scenes, game);
}
