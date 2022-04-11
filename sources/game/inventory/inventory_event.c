/*
** EPITECH PROJECT, 2022
** my_defender
** File description:
** inventory_event
*/

#include "my_structures.h"

static void draw_in_inventory_two(game_scene_t *game, int i)
{
    switch (game->inventory[i]->id) {
    case 3:
        game->inventory[i]->texture =
        sfTexture_createFromFile("assets/wizard2.png", NULL);
        sfRectangleShape_setTexture
        (game->inventory[i]->rect, game->inventory[i]->texture, sfFalse);
        sfRectangleShape_setFillColor(game->inventory[i]->rect, sfWhite);
        break;
    case 4:
        game->inventory[i]->texture =
        sfTexture_createFromFile("assets/wizard3.png", NULL);
        sfRectangleShape_setTexture(game->inventory[i]->rect,
        game->inventory[i]->texture, sfFalse);
        sfRectangleShape_setFillColor(game->inventory[i]->rect, sfWhite);
        break;
    }
}

void draw_in_inventory(game_scene_t *game, int i)
{
    switch (game->inventory[i]->id) {
        case 1:
        game->inventory[i]->texture =
        sfTexture_createFromFile("assets/archer.png", NULL);
        sfRectangleShape_setTexture
        (game->inventory[i]->rect, game->inventory[i]->texture, sfFalse);
        sfRectangleShape_setFillColor(game->inventory[i]->rect, sfWhite);
        break;
        case 2:
        game->inventory[i]->texture =
        sfTexture_createFromFile("assets/wizard1.png", NULL);
        sfRectangleShape_setTexture
        (game->inventory[i]->rect, game->inventory[i]->texture, sfFalse);
        sfRectangleShape_setFillColor(game->inventory[i]->rect, sfWhite);
        break;
    }
    draw_in_inventory_two(game, i);
}

void put_tower_inventory(game_scene_t *game)
{
    int i = 1;

    for (; i != 9; i++) {
        if (game->inventory[i]->id == 0) {
            game->inventory[i]->id = game->shop[6]->id;
            game->shop[6]->id = 0;
            game->shop[0]->texture =
            sfTexture_createFromFile("assets/shop.png", NULL);
            sfRectangleShape_setTexture
            (game->shop[0]->rect, game->shop[0]->texture, sfFalse);
            sfRectangleShape_setFillColor(game->shop[6]->rect, sfTransparent);
            break;
        }
    }
    if (i == 9) {
        sfRectangleShape_setTexture
        (game->shop[0]->rect, game->shop[0]->texture, sfFalse);
        sfRectangleShape_setFillColor(game->shop[6]->rect, sfTransparent);
        game->shop[6]->id = 0;
    }
}

int inventory_full(game_scene_t *game)
{
    int i = 1;

    for (; game->inventory[i]->id != 0 && i != 9; i++);
    if (i == 9)
        return (0);
    return (1);
}
