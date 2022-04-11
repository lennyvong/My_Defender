/*
** EPITECH PROJECT, 2022
** my_defender
** File description:
** buy_towers
*/

#include "my_structures.h"

void draw_in_inventory(game_scene_t *game, int i);
void put_tower_inventory(game_scene_t *game);
int inventory_full(game_scene_t *game);
int my_getnbr(char const *str);

static void show_tower_two(game_scene_t *game, int i)
{
    switch (i) {
    case 3:
        game->shop[6]->texture =
        sfTexture_createFromFile("assets/wizard2.png", NULL);
        sfRectangleShape_setFillColor(game->shop[6]->rect, sfWhite);
        game->shop[6]->id = i;
        break;
    case 4:
        game->shop[6]->texture =
        sfTexture_createFromFile("assets/wizard3.png", NULL);
        sfRectangleShape_setFillColor(game->shop[6]->rect, sfWhite);
        game->shop[6]->id = i;
        break;
    }
    game->shop[6]->id = i;
    game->shop[6]->string = game->shop[i]->string;
    sfText_setString(game->shop[6]->price, game->shop[6]->string);
    sfRectangleShape_setTexture
    (game->shop[6]->rect, game->shop[6]->texture, sfFalse);
}

static void show_tower(game_scene_t *game, int i)
{
    switch (i) {
        case 1:
        game->shop[6]->texture =
        sfTexture_createFromFile("assets/archer.png", NULL);
        sfRectangleShape_setFillColor(game->shop[6]->rect, sfWhite);
        game->shop[6]->id = i;
        break;
        case 2:
        game->shop[6]->texture =
        sfTexture_createFromFile("assets/wizard1.png", NULL);
        sfRectangleShape_setFillColor(game->shop[6]->rect, sfWhite);
        game->shop[6]->id = i;
        break;
    }
    show_tower_two(game, i);
    game->shop[6]->id = i;
    game->shop[6]->string = game->shop[i]->string;
    sfText_setString(game->shop[6]->price, game->shop[6]->string);
    sfRectangleShape_setTexture
    (game->shop[6]->rect, game->shop[6]->texture, sfFalse);
}

static void check_select_tower(manager_t *manager, game_scene_t *game)
{
    if (game->shop[6]->id != 0
    && manager->event.type == sfEvtMouseButtonPressed
    && manager->event.mouseButton.x >= 1730
    && manager->event.mouseButton.x <= 1880
    && manager->event.mouseButton.y >= 530
    && manager->event.mouseButton.y <= 600 && inventory_full(game) != 0
    && game->nb >= my_getnbr(game->shop[6]->string)) {
        sfSound_play(game->coin);
        game->nb -= my_getnbr(game->shop[6]->string);
        sfText_setString(game->shop[6]->price, "0");
        game->shop[0]->texture =
        sfTexture_createFromFile("assets/shop2.png", NULL);
        sfRectangleShape_setTexture
        (game->shop[0]->rect, game->shop[0]->texture, sfFalse);
        put_tower_inventory(game);
        for (int i = 1; i != 9; i++)
            draw_in_inventory(game, i);
    }
}

void check_which_tower(game_scene_t *game, manager_t *manager)
{
    for (int i = 1; i != 7; i++) {
        if (manager->event.mouseButton.x >= game->shop[i]->position.x
        && manager->event.mouseButton.x <= game->shop[i]->position.x + 60
        && manager->event.mouseButton.y >= game->shop[i]->position.y
        && manager->event.mouseButton.y <= game->shop[i]->position.y + 100) {
            show_tower(game, i);
        }
    }
    check_select_tower(manager, game);
}