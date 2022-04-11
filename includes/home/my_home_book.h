/*
** EPITECH PROJECT, 2022
** my_home_book.h
** File description:
** my_home_book
*/

#ifndef MY_HOME_BOOK_H_
    #define MY_HOME_BOOK_H_

typedef struct book_s book_t;
typedef struct scenes_s scenes_t;

void display_book(scenes_t *scenes, float speed);
void init_book(book_t *book);
void init_smoke(smoke_t *smoke);
void display_smoke(scenes_t *scenes);
#endif /* !MY_HOME_BOOK_H_ */
