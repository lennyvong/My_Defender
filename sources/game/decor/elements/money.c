/*
** EPITECH PROJECT, 2022
** my_defender
** File description:
** money
*/

#include "my_structures.h"

char *my_itoa(int nb);

void display_money(manager_t *manager, game_scene_t *game)
{
    game->money_time = sfClock_getElapsedTime(game->money_clock);
    game->sec = game->money_time.microseconds / 1000000.0;
    if (game->sec > 1) {
        game->nb++;
        game->string = my_itoa(game->nb);
        sfText_setString(game->text_money, game->string);
        sfClock_restart(game->money_clock);
    }
    sfRenderWindow_drawSprite(manager->window, game->sprite_money, NULL);
    sfRenderWindow_drawText(manager->window, game->text_money, NULL);
}

void set_money(game_scene_t *game)
{
    game->nb = 20;
    game->sec = 0;
    game->string = NULL;
    game->money_clock = sfClock_create();
    game->text_money = sfText_create();
    game->font_money = sfFont_createFromFile("assets/cartoon.ttf");
    sfText_setPosition(game->text_money, (sfVector2f) {120, 5});
    sfText_setCharacterSize(game->text_money, 75);
    sfText_setString(game->text_money, game->string);
    sfText_setColor(game->text_money, sfYellow);
    sfText_setFont(game->text_money, game->font_money);
    game->texture_money = sfTexture_createFromFile("assets/money.png", NULL);
    game->sprite_money = sfSprite_create();
    sfSprite_setTexture(game->sprite_money, game->texture_money, sfFalse);
    sfSprite_setPosition(game->sprite_money, (sfVector2f) {0, 0});
    sfSprite_setScale(game->sprite_money, (sfVector2f) {2, 2});
}
