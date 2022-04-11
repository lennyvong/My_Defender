/*
** EPITECH PROJECT, 2022
** my_defender
** File description:
** display_all
*/


#include <stdlib.h>
#include <time.h>
#include "my_structures.h"
#include "game/my_game_decor.h"
#include "game/my_game_decor.h"
#include "game/enemies/my_game_enemies.h"
#include "game/enemies/my_enemies_deplacements.h"
#include "game/my_game.h"
#include "end_game/end_game.h"
void display_towers(scenes_t *scenes);

void display_all(scenes_t *scenes, tab_enemies_t *tab)
{
    display_decor(scenes->game->info, scenes->game, scenes->manager);
    display_enemies(scenes->manager, scenes->game, tab);
    display_towers(scenes);
    display_after_enemies(scenes);
    check_end_game(scenes);
    display_money(scenes->manager, scenes->game);
    for (int i = 0; i != 9; i++)
        sfRenderWindow_drawRectangleShape
        (scenes->manager->window, scenes->game->inventory[i]->rect, NULL);
    for (int i = 0; i != 7; i++) {
        sfRenderWindow_drawRectangleShape
        (scenes->manager->window, scenes->game->shop[i]->rect, NULL);
        sfRenderWindow_drawText
        (scenes->manager->window, scenes->game->shop[i]->price, NULL);
    }
}
