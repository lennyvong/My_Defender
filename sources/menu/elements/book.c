/*
** EPITECH PROJECT, 2022
** book.c
** File description:
** book
*/

#include "my_structures.h"
#include "my_lib.h"

void init_book(book_t *book)
{
    book->texture_book = sfTexture_createFromFile("assets/book.png", NULL);
    book->sprite_book = sfSprite_create();
    book->rect_book.top = 0;
    book->rect_book.left = 0;
    book->rect_book.width = 750;
    book->rect_book.height = 636;
    sfSprite_setTexture(book->sprite_book, book->texture_book, sfFalse);
    sfSprite_setPosition(book->sprite_book, (sfVector2f) {440, 95});
    sfSprite_setScale(book->sprite_book, (sfVector2f) {1.3, 1.3});
    sfSprite_setTextureRect(book->sprite_book, book->rect_book);
}

void display_book(scenes_t *scenes, float speed)
{
    scenes->book->time_book = sfClock_getElapsedTime(scenes->book->clock_book);
    scenes->book->sec_book = scenes->book->time_book.microseconds / 1000000.0;
    if (scenes->book->sec_book > speed) {
        move_rect(&scenes->book->rect_book, 750, 14250, 0);
        sfSprite_setTextureRect
        (scenes->book->sprite_book, scenes->book->rect_book);
        sfClock_restart(scenes->book->clock_book);
    }
    sfRenderWindow_drawSprite
    (scenes->manager->window, scenes->book->sprite_book, NULL);
}
